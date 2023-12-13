#include "jkff.cpp"
#include "systemc.h"

void set_val(sc_signal<sc_logic>& A,sc_signal<sc_logic>& B,bool a, bool b){
    A=(sc_logic)a;
    B=(sc_logic)b;
}


int sc_main(int argc, char* argv[]){
    sc_signal<sc_logic>j,k,q,qb,rst;

    // clock signal
    sc_clock clk ("clk",10,SC_NS);

    // Initiate the DUT
    jkff JK("jkff");
    JK.clk(clk);
    JK.rst(rst);
    JK.j(j);
    JK.k(k);
    JK.q(q);
    JK.qb(qb); 

    // Open VCD file 
    sc_trace_file *wf=sc_create_vcd_trace_file("jkff");

    // Dump the desired signals 
    sc_trace(wf,clk,"clk");
    sc_trace(wf,rst,"rst");
    sc_trace(wf,j,"j");
    sc_trace(wf,k,"k");
    sc_trace(wf,q,"q");
    sc_trace(wf,qb,"qb");

    // initializations:
    rst=sc_logic_0;
    set_val(j,k,0,0);
    sc_start(1,SC_NS);
    rst=sc_logic_1;
    sc_start(1,SC_NS);
    

    // simulation
    sc_start(7,SC_NS);
    cout<<"@"<<sc_time_stamp()<<": "<<"clk: "<<clk<<", J: "<<j<<", K: "<<k<<", Q: "<<q<<", Qb: "<<qb<<endl;

    set_val(j,k,0,0);
    sc_start(11,SC_NS);
    cout<<"@"<<sc_time_stamp()<<": "<<"clk: "<<clk<<", J: "<<j<<", K: "<<k<<", Q: "<<q<<", Qb: "<<qb<<endl;

    set_val(j,k,1,0);
    sc_start(13,SC_NS);
    cout<<"@"<<sc_time_stamp()<<": "<<"clk: "<<clk<<", J: "<<j<<", K: "<<k<<", Q: "<<q<<", Qb: "<<qb<<endl;

    set_val(j,k,0,1);
    sc_start(20,SC_NS);
    cout<<"@"<<sc_time_stamp()<<": "<<"clk: "<<clk<<", J: "<<j<<", K: "<<k<<", Q: "<<q<<", Qb: "<<qb<<endl;

    set_val(j,k,1,1);
    sc_start(11,SC_NS);
    cout<<"@"<<sc_time_stamp()<<": "<<"clk: "<<clk<<", J: "<<j<<", K: "<<k<<", Q: "<<q<<", Qb: "<<qb<<endl;

    set_val(j,k,1,1);
    sc_start(9,SC_NS);
    cout<<"@"<<sc_time_stamp()<<": "<<"clk: "<<clk<<", J: "<<j<<", K: "<<k<<", Q: "<<q<<", Qb: "<<qb<<endl;
    return 0;
}