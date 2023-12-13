#include "../6_dff/dff.cpp"
#include "systemc.h"

SC_MODULE(siso_sr){
    sc_in<sc_logic> din,rst;
    sc_in_clk clk;
    sc_out<sc_logic> dout;
    sc_signal<sc_logic> d1,d2,d3,nc1,nc2,nc3,nc4;

    dff D1;
    dff D2;
    dff D3;
    dff D4;

    SC_CTOR(siso_sr):D1("D1"),D2("D2"),D3("D3"),D4("D4"){
        D1.d(din);
        D1.rst(rst);
        D1.clk(clk);
        D1.q(d1);
        D1.qb(nc1);

        D2.d(d1);
        D2.rst(rst);
        D2.clk(clk);
        D2.q(d2);
        D2.qb(nc2);

        D3.d(d2);
        D3.rst(rst);
        D3.clk(clk);
        D3.q(d3);
        D3.qb(nc3);

        D4.d(d3);
        D4.rst(rst);
        D4.clk(clk);
        D4.q(dout);
        D4.qb(nc4);
    }
};