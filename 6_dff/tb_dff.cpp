#include "dff.cpp"
#include "systemc.h"

int sc_main(int argc, char* argv[]){
    sc_signal<sc_logic>d,q,qb,rst;
    // clock signal
    sc_clock clk ("clk",10,SC_NS);
    // Initiate the DUT
    dff D("dff");
    D.clk(clk);
    D.rst(rst);
    D.d(d);
    D.q(q);
    D.qb(qb);

    // Open VCD file 
    sc_trace_file *wf=sc_create_vcd_trace_file("dff");

    // Dump the desired signals 
    sc_trace(wf,clk,"clk");
    sc_trace(wf,rst,"rst");
    sc_trace(wf,d,"d");
    sc_trace(wf,q,"q");
    sc_trace(wf,qb,"qb");

    // initializations:
    rst=sc_logic_0;
    d=sc_logic_0;
    sc_start(1,SC_NS);
    rst=sc_logic_1;
    sc_start(1,SC_NS);

    // simulation
    d=sc_logic_0;
    sc_start(11,SC_NS);
    cout<<"@"<<sc_time_stamp()<<": "<<"clk: "<<clk<<", D: "<<d<<", Q: "<<q<<", Qb: "<<qb<<endl;
    d=sc_logic_1;
    sc_start(17,SC_NS);
    cout<<"@"<<sc_time_stamp()<<": "<<"clk: "<<clk<<", D: "<<d<<", Q: "<<q<<", Qb: "<<qb<<endl;
    d=sc_logic_0;
    sc_start(3,SC_NS);
    cout<<"@"<<sc_time_stamp()<<": "<<"clk: "<<clk<<", D: "<<d<<", Q: "<<q<<", Qb: "<<qb<<endl;
    d=sc_logic_1;
    sc_start(10,SC_NS);
    cout<<"@"<<sc_time_stamp()<<": "<<"clk: "<<clk<<", D: "<<d<<", Q: "<<q<<", Qb: "<<qb<<endl;
    d=sc_logic_0;
    sc_start(11,SC_NS);
    cout<<"@"<<sc_time_stamp()<<": "<<"clk: "<<clk<<", D: "<<d<<", Q: "<<q<<", Qb: "<<qb<<endl;
    d=sc_logic_1;
    sc_start(9,SC_NS);
    cout<<"@"<<sc_time_stamp()<<": "<<"clk: "<<clk<<", D: "<<d<<", Q: "<<q<<", Qb: "<<qb<<endl;
    return 0;
}