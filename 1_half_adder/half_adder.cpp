#include "half_adder.h"

// Process Definition 
void half_adder::prc_half_adder(){
    sum=a^b;
    carry=a&b;
}