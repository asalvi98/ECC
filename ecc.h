#include<stdio.h>
#include"ap_fixed.h"
#include"ap_int.h"

typedef ap_uint<5> data_5;
typedef ap_uint<8> data_8;
typedef ap_uint<13> data_13;
typedef ap_uint<1> data_1;
void ecc_encoder(data_8 data1, data_5 * output);

