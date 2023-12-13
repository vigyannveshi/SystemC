#include "systemc.h"

sc_logic inv(sc_logic a){
    if(a==sc_logic_0){
        return sc_logic_1;
    }
    else if(a==sc_logic_1){
        return sc_logic_0;
    }
    else if(a==sc_logic_X){
        return sc_logic_X;
    }
    else{
        return sc_logic_Z;
    }

}   

SC_MODULE(srff){
    sc_in_clk clk;
    sc_in<sc_logic>s,r,rst;
    sc_logic temp;
    sc_out<sc_logic>q,qb;

    void prc_srff(){
        if (rst==sc_logic_0){
            temp=sc_logic_0;
        }
        else if(clk.posedge()){
            if(s==sc_logic_1 && r==sc_logic_1){
                temp=sc_logic_X;
            }
            else if(s==sc_logic_0 && r==sc_logic_1){
                temp=sc_logic_0;
            }
            else if(s==sc_logic_1 && r==sc_logic_0){
                temp=sc_logic_1;
            }
            else{
                temp=temp;
            }

        }
        q=temp;
        qb=inv(temp);
    } 

    SC_CTOR(srff){
        SC_METHOD(prc_srff);
        sensitive<<clk;
    }

};