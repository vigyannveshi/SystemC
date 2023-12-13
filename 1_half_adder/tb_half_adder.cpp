// Test bench for Half Adder

#include "systemc.h"
#include "half_adder.cpp"

void set_val(sc_signal<bool>& a, sc_signal<bool>&  b,int i){
    switch (i)
    {
        case 0:
            a=0;
            b=0;
            break;
        case 1:
            a=0;
            b=1;
            break;
        case 2:
            a=1;
            b=0;
            break;
        case 3:
            a=1;
            b=1;
            break;
    
        default:
            a=0;
            b=0;
            break;
    }
}

int sc_main (int argc,char* argv[]){
    sc_signal<bool> a;
    sc_signal<bool> b;
    sc_signal<bool> sum;
    sc_signal<bool> carry;

    // Connecting Design under test
    half_adder ha("ha");
    ha.a(a);
    ha.b(b);
    ha.sum(sum);
    ha.carry(carry);


    // Open VCD file
    sc_trace_file *wf =sc_create_vcd_trace_file("half_adder");

    // Dump the desired signals
    sc_trace(wf,a,"a");
    sc_trace(wf,b,"b");
    sc_trace(wf,sum,"sum");
    sc_trace(wf,carry,"carry");


    // simulate for 40s, and change values every 10ns
    for(int i=0;i<4;i++){
        for(int j=0;j<10;j++){
            set_val(a,b,i);
            sc_start(1,SC_NS);
        }
    cout<<"@"<<sc_time_stamp()<<": "<<"a: "<<a<<", b: "<<b<<", sum: "<<sum<<", carry"<<carry<<endl;
    }


    // close file
    sc_close_vcd_trace_file(wf);
    // terminate simulation
    return 0;// Terminate simulation
}