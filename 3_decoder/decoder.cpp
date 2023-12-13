#include "decoder.h"

void decoder_2x4::prc_decoder(){
    if(A.read() == "00"){
        Y.write(sc_lv<4>("0001"));
    }
    else if(A.read() == "01"){
        Y.write(sc_lv<4>("0010"));
    }
    else if(A.read() == "10"){
        Y.write(sc_lv<4>("0100"));
    }
    else{
        Y.write(sc_lv<4>("1000"));
    }
}