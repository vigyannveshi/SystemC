// Structural Modelling of RCA
#include "systemc.h"
#include "../4_full_adder/full_adder.cpp"


SC_MODULE(rca){
    sc_in<sc_logic>A0,A1,A2,A3;
    sc_in<sc_logic>B0,B1,B2,B3;
    sc_in<sc_logic>Cin;
    sc_out<sc_logic>S0,S1,S2,S3;
    sc_out<sc_logic>Cout;
    sc_signal<sc_logic> c1,c2,c3;

    // instantiating modules of full_adder
    full_adder F1;
    full_adder F2;
    full_adder F3;
    full_adder F4;

    SC_CTOR(rca):F1("F1"),F2("F2"),F3("F3"),F4("F4"){
        // sensitivity list is not needed
        // sensitive<<A0<<A1<<A2<<A3<<B0<<B1<<B2<<B3<<Cin;
        F1.a(A0);
        F1.b(B0);
        F1.s(S0);
        F1.cin(Cin);
        F1.cout(c1);

        F2.a(A1);
        F2.b(B1);
        F2.s(S1);
        F2.cin(c1);
        F2.cout(c2);

        F3.a(A2);
        F3.b(B2);
        F3.s(S2);
        F3.cin(c2);
        F3.cout(c3);

        F4.a(A3);
        F4.b(B3);
        F4.s(S3);
        F4.cin(c3);
        F4.cout(Cout);

    }
};
