#include "systemc.h"

SC_MODULE(mux_4x1){
    // Defining inputs and outputs
    sc_in<sc_lv<4>> I;
    sc_in<sc_lv<2>> S;
    sc_out<sc_logic>Y;

    void prc_mux();

    SC_CTOR(mux_4x1){
        SC_METHOD(prc_mux);
        sensitive<<I<<S;
    }
};
