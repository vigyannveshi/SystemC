#include "systemc.h"
#include "full_adder.cpp"


void disp(sc_signal<sc_logic>& A, sc_signal<sc_logic>& B,sc_signal<sc_logic>& Cin, sc_signal<sc_logic>& S,sc_signal<sc_logic>& Cout){
    cout<<"@"<<sc_time_stamp()<<": \n"<<"A: "<<A<<", B: "<<B<<", Cin: "<<Cin<<"\nS: "<<S<<",Cout: "<<Cout<<endl;
}

void set_val(sc_signal<sc_logic>& A,sc_signal<sc_logic>& B,sc_signal<sc_logic>& Cin,bool a, bool b,bool cin){
    A=(sc_logic)a;
    B=(sc_logic)b;
    Cin=(sc_logic)cin;
}

int sc_main(int argc, char* argv[]){
    // Defining signals
    sc_signal<sc_logic> A,B,Cin,S,Cout;

    // Initialize DUT
    full_adder fa("full_adder");
    fa.a(A);
    fa.b(B);
    fa.cin(Cin);
    fa.s(S);
    fa.cout(Cout);

    // Open vcd file
    sc_trace_file *wf=sc_create_vcd_trace_file("full_adder");
    
    // Dump the desired signals
    sc_trace(wf,A,"A");
    sc_trace(wf,B,"B");
    sc_trace(wf,Cin,"Cin");
    sc_trace(wf,S,"S");
    sc_trace(wf,Cout,"Cout");

    // Simulation
    for(int i=0;i<=1;i++){
        for(int j=0;j<=1;j++){
            for(int k=0;k<=1;k++){
                set_val(A,B,Cin,i,j,k);
                sc_start(10,SC_NS);
                disp(A,B,Cin,S,Cout);
            }
        }
    }

    // close file
    sc_close_vcd_trace_file(wf);
    // terminate simulation
    return 0;// Terminate simulation
    
}