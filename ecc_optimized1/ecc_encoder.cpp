#include<stdio.h>
#include<iostream>
#include"ap_fixed.h"
#include"ap_int.h"
#include"ecc.h"
#include<string>
using namespace::std;




void ecc_encoder(
		data_8 data1, 	//in
		data_5 *output 	//out
		)
{
	data_8 pattern[5];

	int i, j, size_ecc=5, size_msg=8;

	pattern[0] = 0b11110000;
	pattern[1] = 0b10001110;
	pattern[2] = 0b01101101;
	pattern[3] = 0b01011011;
	pattern[4] = 0b10110111;

	data_5 check_bits;


	data_8 temp_bit;
	for(j=0;j<size_msg;j++) //loop order changed
	{
		check_bits[i]=0;
		temp_bit = pattern[i] & data1;

		for(i=0;i<size_ecc;i++)
		{
			check_bits[i]=check_bits[i]^temp_bit[j];
		}
	}
//	cout<<" "<<int(check_bits);
	*output = check_bits;
}

