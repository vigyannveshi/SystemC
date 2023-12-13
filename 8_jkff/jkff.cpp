#include "systemc.h"


SC_MODULE(jkff){
    sc_in_clk clk;
    sc_in<sc_logic>j,k,rst;
    sc_logic temp;
    sc_out<sc_logic>q,qb;
     
    void prc_jkff(){
        if (rst==sc_logic_0){
            temp=sc_logic_0;
        }
        else if(clk.posedge()){
            if(j==sc_logic_1 && k==sc_logic_1){
                temp=(temp==sc_logic_1)?(sc_logic_0):(sc_logic_1);
            }
            else if(j==sc_logic_0 && k==sc_logic_1){
                temp=sc_logic_0;
            }
            else if(j==sc_logic_1 && k==sc_logic_0){
                temp=sc_logic_1;
            }
            else{
                temp=temp;
            }

        }
        q=temp;
        qb=(temp==sc_logic_1)?(sc_logic_0):(sc_logic_1);
    } 

    SC_CTOR(jkff){
        SC_METHOD(prc_jkff);
        sensitive<<clk;
    }

};