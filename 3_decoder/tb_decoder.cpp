#include "systemc.h"
#include <decoder.cpp>

void set_val(sc_signal<sc_lv<2>>& A,int i){
    switch (i)
    {
        case 0:
            A.write(sc_lv<2>("00"));
            break;
        case 1:
            A.write(sc_lv<2>("01"));
            break;
        case 2:
            A.write(sc_lv<2>("10"));
            break;
        case 3:
            A.write(sc_lv<2>("11"));
            break;
        default:
            A.write(sc_lv<2>("00"));
            break;
    }
}

int sc_main(int argc, char* argv[]){
    // Defining signals
    sc_signal<sc_lv<2>> A;
    sc_signal<sc_lv<4>> Y;

    // Initialize DUT
    decoder_2x4 dec("dec");
    dec.A(A);
    dec.Y(Y);

    // Open vcd file
    sc_trace_file *wf=sc_create_vcd_trace_file("dec");
    
    // Dump the desired signals
    sc_trace(wf,A,"A");
    sc_trace(wf,Y,"Y");

      // simulate for 40s, and change values every 10ns
    for(int i=0;i<4;i++){
        for(int j=0;j<10;j++){
            set_val(A,i);
            sc_start(1,SC_NS);
        }
        cout<<"@"<<sc_time_stamp()<<": "<<"A: "<<A<<", Y: "<<Y<<endl;
    }
    cout<<endl;

    // close file
    sc_close_vcd_trace_file(wf);
    // terminate simulation
    return 0;// Terminate simulation
    
}