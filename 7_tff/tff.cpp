#include "systemc.h"


SC_MODULE(tff){
    sc_in_clk clk;
    sc_in<sc_logic>t,rst;
    sc_logic temp;
    sc_out<sc_logic>q,qb;
     
    void prc_tff(){
        if (rst==sc_logic_0){
            temp=sc_logic_0;
        }
        else if(clk.posedge()){
            if (t==sc_logic_1){
                temp=(temp==sc_logic_1)?(sc_logic_0):(sc_logic_1);
            }
        }
        q=temp;
        qb=(temp==sc_logic_1)?(sc_logic_0):(sc_logic_1);
    } 

    SC_CTOR(tff){
        SC_METHOD(prc_tff);
        sensitive<<clk;
    }

};