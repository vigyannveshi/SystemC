#include "systemc.h"

SC_MODULE(full_adder){
    // input-output
    sc_in <sc_logic> a,b,cin;
    sc_out<sc_logic> s,cout;

    SC_CTOR(full_adder){
        SC_METHOD(prc_full_adder);
        sensitive<<a<<b<<cin;
    }

    void prc_full_adder(){
        s=a^b^cin;
        cout=(a^b)&cin|(a&b);
    }
};
