#include<stdio.h>
#include<iostream>
#include"ap_fixed.h"
#include"ap_int.h"
#include"ecc.h"
#include<string>
#include<hls_stream.h>
#include"ap_axi_sdata.h"
using namespace::std;




void ecc_encoder(
		hls::stream<stream_8> &data1, 	//in
		hls::stream<stream_5> &output 	//out
		)
{
#pragma HLS INTERFACE axis port=data1
#pragma HLS INTERFACE axis port=output
#pragma HLS INTERFACE s_axilite port=return
	stream_8 pattern[5];






	int i, j, k, size_ecc=5, size_msg=8;
	stream_8 inputs[256]; //array to stream the inputs into
	for(k=0;k<256;k++)
	{
	inputs[k]=data1.read();
	}


	pattern[0] = 0b11110000;
	pattern[1] = 0b10001110;
	pattern[2] = 0b01101101;
	pattern[3] = 0b01011011;
	pattern[4] = 0b10110111;
//#pragma HLS ARRAY_PARTITION variable=pattern type=cyclic factor=5 dim=1
	data_5 check_bits[256];


	data_8 temp_bit;
	for(k=0;k<256;k++)
	{
	for(j=0;j<size_msg;j++)

	{
//#pragma HLS UNROLL factor=7
		check_bits[k][i]=0;
		temp_bit = pattern[i] & inputs[k];

		for(i=0;i<size_ecc;i++)
		{
			check_bits[k][i]=check_bits[k][i]^temp_bit[j];
		}
	}
	}
//	cout<<" "<<int(check_bits);
	for(k=0;k<256;k++)
		{
		output.write(check_bits[k]);
		}
//	*output = check_bits;
}

