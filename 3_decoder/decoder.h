#include "systemc.h"

SC_MODULE(decoder_2x4){
    sc_in<sc_lv<2>> A;
    sc_out<sc_lv<4>> Y;

    void prc_decoder();

    SC_CTOR(decoder_2x4){
        SC_METHOD(prc_decoder);
        sensitive<<A;
    }
};