#include "tff.cpp"
#include "systemc.h"

int sc_main(int argc, char* argv[]){
    sc_signal<sc_logic>t,q,qb,rst;

    // clock signal
    sc_clock clk ("clk",10,SC_NS);

    // Initiate the DUT
    tff T("tff");
    T.clk(clk);
    T.rst(rst);
    T.t(t);
    T.q(q);
    T.qb(qb); 

    // Open VCD file 
    sc_trace_file *wf=sc_create_vcd_trace_file("tff");

    // Dump the desired signals 
    sc_trace(wf,clk,"clk");
    sc_trace(wf,rst,"rst");
    sc_trace(wf,t,"t");
    sc_trace(wf,q,"q");
    sc_trace(wf,qb,"qb");

    // initializations:
    rst=sc_logic_0;
    t=sc_logic_0;
    sc_start(1,SC_NS);
    rst=sc_logic_1;
    sc_start(1,SC_NS);
    

    // simulation
    sc_start(7,SC_NS);
    cout<<"@"<<sc_time_stamp()<<": "<<"clk: "<<clk<<", T: "<<t<<", Q: "<<q<<", Qb: "<<qb<<endl;
    t=sc_logic_1;
    sc_start(11,SC_NS);
    cout<<"@"<<sc_time_stamp()<<": "<<"clk: "<<clk<<", T: "<<t<<", Q: "<<q<<", Qb: "<<qb<<endl;
    t=sc_logic_0;
    sc_start(13,SC_NS);
    cout<<"@"<<sc_time_stamp()<<": "<<"clk: "<<clk<<", T: "<<t<<", Q: "<<q<<", Qb: "<<qb<<endl;
    t=sc_logic_1;
    sc_start(20,SC_NS);
    cout<<"@"<<sc_time_stamp()<<": "<<"clk: "<<clk<<", T: "<<t<<", Q: "<<q<<", Qb: "<<qb<<endl;
    t=sc_logic_0;
    sc_start(11,SC_NS);
    cout<<"@"<<sc_time_stamp()<<": "<<"clk: "<<clk<<", T: "<<t<<", Q: "<<q<<", Qb: "<<qb<<endl;
    t=sc_logic_1;
    sc_start(9,SC_NS);
    cout<<"@"<<sc_time_stamp()<<": "<<"clk: "<<clk<<", T: "<<t<<", Q: "<<q<<", Qb: "<<qb<<endl;
    return 0;
}