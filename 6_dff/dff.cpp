#include "systemc.h"


SC_MODULE(dff){
    sc_in_clk clk;
    sc_in<sc_logic>d,rst;
    sc_logic temp;
    sc_out<sc_logic>q,qb;
    

    void prc_dff(){
        if (rst==sc_logic_0){
                temp=sc_logic_0;
        }
        else if(clk.posedge()){
            temp=d;
        }
        q=temp;
        qb=(temp==sc_logic_1)?(sc_logic_0):(sc_logic_1);
    } 

    SC_CTOR(dff){
        SC_METHOD(prc_dff);
        sensitive<<clk;
    }

};