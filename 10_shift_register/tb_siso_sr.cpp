#include "siso_sr.cpp"
#include "systemc.h"


int sc_main(int argc, char* argv[]){
    sc_signal<sc_logic>din,dout,rst;

    // clock signal
    sc_clock clk ("clk",10,SC_NS);

    // Initiate the DUT
    siso_sr SR("siso_sr");
    SR.clk(clk);
    SR.rst(rst);
    SR.din(din);
    SR.dout(dout);

    // Open VCD file 
    sc_trace_file *wf=sc_create_vcd_trace_file("siso_sr");

    // Dump the desired signals 
    sc_trace(wf,clk,"clk");
    sc_trace(wf,rst,"rst");
    sc_trace(wf,din,"din");
    sc_trace(wf,dout,"dout");


    // initializations:
    din=sc_logic_0;
    rst=sc_logic_0;
    sc_start(1,SC_NS);
    rst=sc_logic_1;
    sc_start(1,SC_NS);
    

    // simulation
    din=sc_logic_1;
    sc_start(11,SC_NS);
    cout<<"@"<<sc_time_stamp()<<": "<<"clk: "<<clk<<", din: "<<din<<", dout: "<<dout<<endl;

    din=sc_logic_1;
    sc_start(11,SC_NS);
    cout<<"@"<<sc_time_stamp()<<": "<<"clk: "<<clk<<", din: "<<din<<", dout: "<<dout<<endl;

    din=sc_logic_0;
    sc_start(11,SC_NS);
    cout<<"@"<<sc_time_stamp()<<": "<<"clk: "<<clk<<", din: "<<din<<", dout: "<<dout<<endl;

    din=sc_logic_1;
    sc_start(11,SC_NS);
    cout<<"@"<<sc_time_stamp()<<": "<<"clk: "<<clk<<", din: "<<din<<", dout: "<<dout<<endl;

    din=sc_logic_0;
    sc_start(11,SC_NS);
    cout<<"@"<<sc_time_stamp()<<": "<<"clk: "<<clk<<", din: "<<din<<", dout: "<<dout<<endl;

    din=sc_logic_0;
    sc_start(11,SC_NS);
    cout<<"@"<<sc_time_stamp()<<": "<<"clk: "<<clk<<", din: "<<din<<", dout: "<<dout<<endl;

    din=sc_logic_0;
    sc_start(11,SC_NS);
    cout<<"@"<<sc_time_stamp()<<": "<<"clk: "<<clk<<", din: "<<din<<", dout: "<<dout<<endl;

    return 0;
}