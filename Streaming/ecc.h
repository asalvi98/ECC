#include<stdio.h>
#include"ap_fixed.h"
#include"ap_int.h"
#include"ap_axi_sdata.h"
#include<hls_stream.h>

typedef ap_uint<5> data_5;
typedef ap_uint<8> data_8;
typedef ap_uint<13> data_13;
typedef ap_uint<1> data_1;
typedef ap_uint<4> data_4;

typedef ap_axiu<5, 0, 0, 0> stream_5;
typedef ap_axiu<8, 0, 0, 0> stream_8;


void ecc_encoder(
		hls::stream<stream_8> &data1,		//in
		hls::stream<stream_5>	&output		//out
		);
void ecc_decoder(
		data_8 	data_in, 	//in
		data_5 	ecc_in,		//in
		data_8 	*output,	//out
		data_1 	*valid		//out
		);

