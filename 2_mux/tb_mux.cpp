#include "systemc.h"
#include <mux.cpp>

void set_val(sc_signal<sc_lv<2>>& S,int i){
    switch (i)
    {
        case 0:
            S.write(sc_lv<2>("00"));
            break;
        case 1:
            S.write(sc_lv<2>("01"));
            break;
        case 2:
            S.write(sc_lv<2>("10"));
            break;
        case 3:
            S.write(sc_lv<2>("11"));
            break;
        default:
            S.write(sc_lv<2>("00"));
            break;
    }
}

int sc_main(int argc, char* argv[]){
    // Defining signals
    sc_signal<sc_lv<4>> I;
    sc_signal<sc_lv<2>> S;
    sc_signal<sc_logic> Y;

    // Initialize DUT
    mux_4x1 mux("mux");
    mux.Y(Y);
    mux.I(I);
    mux.S(S);


    // Open vcd file
    sc_trace_file *wf=sc_create_vcd_trace_file("mux");
    
    // Dump the desired signals
    sc_trace(wf,I,"I");
    sc_trace(wf,S,"S");
    sc_trace(wf,Y,"Y");

      // simulate for 40s, and change values every 10ns
    I.write(sc_lv<4>("0001"));
    for(int i=0;i<4;i++){
        for(int j=0;j<10;j++){
            set_val(S,i);
            sc_start(1,SC_NS);
        }
        cout<<"@"<<sc_time_stamp()<<": "<<"S: "<<S<<", I: "<<I<<", Y: "<<Y<<endl;
    }
    cout<<endl;

    I.write(sc_lv<4>("0010"));
    for(int i=0;i<4;i++){
        for(int j=0;j<10;j++){
            set_val(S,i);
            sc_start(1,SC_NS);
        }
        cout<<"@"<<sc_time_stamp()<<": "<<"S: "<<S<<", I: "<<I<<", Y: "<<Y<<endl;
    }
    cout<<endl;

    I.write(sc_lv<4>("0100"));
    for(int i=0;i<4;i++){
        for(int j=0;j<10;j++){
            set_val(S,i);
            sc_start(1,SC_NS);
        }
        cout<<"@"<<sc_time_stamp()<<": "<<"S: "<<S<<", I: "<<I<<", Y: "<<Y<<endl;
    }
    cout<<endl;

    I.write(sc_lv<4>("1000"));
    for(int i=0;i<4;i++){
        for(int j=0;j<10;j++){
            set_val(S,i);
            sc_start(1,SC_NS);
        }
        cout<<"@"<<sc_time_stamp()<<": "<<"S: "<<S<<", I: "<<I<<", Y: "<<Y<<endl;
    }
    cout<<endl; 

    // close file
    sc_close_vcd_trace_file(wf);
    // terminate simulation
    return 0;// Terminate simulation
    
}