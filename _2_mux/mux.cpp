#include "mux.h"

void mux_4x1::prc_mux(){
    if (S.read() == "00"){
        Y=(sc_logic)I.read()[0];
    }
    else if (S.read() == "01"){
        Y=(sc_logic)I.read()[1];
    }
    else if (S.read() == "10"){
        Y=(sc_logic)I.read()[2];
    }
    else if (S.read() == "11"){
        Y=(sc_logic)I.read()[3];
    }
    else{
        Y=(sc_logic)I.read()[0];
    }
}
