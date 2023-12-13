#include "systemc.h"

// Module Declaration and Module Name
SC_MODULE(half_adder){
    sc_in<bool> a,b;
    sc_out<bool> sum,carry; 

    // Process name (function prototype)
    void prc_half_adder();

    SC_CTOR(half_adder){
        // SC_METHOD --> process type
        SC_METHOD(prc_half_adder);
        sensitive<<a<<b;
    };

};