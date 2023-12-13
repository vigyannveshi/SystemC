#include "systemc.h"
#include "rca.cpp"


void disp(
    sc_signal<sc_logic>& A0,sc_signal<sc_logic>& A1,sc_signal<sc_logic>& A2,sc_signal<sc_logic>& A3,
    sc_signal<sc_logic>& B0,sc_signal<sc_logic>& B1,sc_signal<sc_logic>& B2,sc_signal<sc_logic>& B3,
    sc_signal<sc_logic>&  Cin,
    sc_signal<sc_logic>& S0,sc_signal<sc_logic>& S1,sc_signal<sc_logic>& S2,sc_signal<sc_logic>& S3,
    sc_signal<sc_logic>& Cout)
{
    cout<<"@"<<sc_time_stamp()<<": \n"<<"A: "<<A3<<A2<<A1<<A0<<", B: "<<B3<<B2<<B1<<B0<<", Cin: "<<Cin<<"\nS: "<<S3<<S2<<S1<<S0<<",Cout: "<<Cout<<endl;
}

void set_val(sc_signal<sc_logic>& A0,sc_signal<sc_logic>& A1,sc_signal<sc_logic>& A2,sc_signal<sc_logic>& A3,bool a0, bool a1,bool a2, bool a3){
    A0=(sc_logic)a0;
    A1=(sc_logic)a1;
    A2=(sc_logic)a2;
    A3=(sc_logic)a3;
}

int sc_main(int argc, char* argv[]){
    // Defining signals
    sc_signal<sc_logic> A0,A1,A2,A3,B0,B1,B2,B3,Cin,S0,S1,S2,S3,Cout;

    // Initialize DUT
    rca r("rca");
    r.A0(A0);
    r.A1(A1);
    r.A2(A2);
    r.A3(A3);
    r.B0(B0);
    r.B1(B1);
    r.B2(B2);
    r.B3(B3);
    r.Cin(Cin);
    r.S0(S0);
    r.S1(S1);
    r.S2(S2);
    r.S3(S3);
    r.Cout(Cout);



    // Open vcd file
    sc_trace_file *wf=sc_create_vcd_trace_file("rca");
    
    // Dump the desired signals
    sc_trace(wf,A0,"A0");
    sc_trace(wf,A1,"A1");
    sc_trace(wf,A2,"A2");
    sc_trace(wf,A3,"A3");

    sc_trace(wf,B0,"B0");
    sc_trace(wf,B1,"B1");
    sc_trace(wf,B2,"B2");
    sc_trace(wf,B3,"B3");

    sc_trace(wf,Cin,"Cin");

    sc_trace(wf,S0,"S0");
    sc_trace(wf,S1,"S1");
    sc_trace(wf,S2,"S2");
    sc_trace(wf,S3,"S3");

    sc_trace(wf,Cout,"Cout");

    // Simulation
    set_val(A3,A2,A1,A0,1,0,1,0);
    set_val(B3,B2,B1,B0,1,0,1,0);
    Cin=(sc_logic)1;
    sc_start(10,SC_NS);
    disp(A0,A1,A2,A3,B0,B1,B2,B3,Cin,S0,S1,S2,S3,Cout);

    set_val(A3,A2,A1,A0,1,1,1,1);
    set_val(B3,B2,B1,B0,1,1,1,1);
    Cin=(sc_logic)0;
    sc_start(10,SC_NS);
    disp(A0,A1,A2,A3,B0,B1,B2,B3,Cin,S0,S1,S2,S3,Cout);

    // close file
    sc_close_vcd_trace_file(wf);
    // terminate simulation
    return 0;// Terminate simulation
    
}