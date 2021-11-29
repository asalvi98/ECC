#include<stdio.h>
#include<iostream>
#include"ap_fixed.h"
#include"ap_int.h"
#include"ecc.h"


using namespace::std;

int main()
{ 	data_5 output_enc;
	data_8 output_dec;
	data_8 output_1;
//	data_8 in_data = 0b11101010;

//	data_8 data_in = 0b11101000;
//	data_5 ecc_in = 0b11111;
	data_8 data_in = 0b00000111;
	data_5 ecc_in = 0b10000;

	data_8 mask = 0b00000001;
	data_1 valid;
	int i=0, j=0;

	for (i=0; i<10; i++)
	{	mask = 0b00000011;
		ecc_encoder(i, &output_enc);
//		printf("Input Data: %d, ECC: %d\n",int(i),int(output_enc));
		for(j=0;j<8;j++)
		{
			ecc_decoder(i^mask,output_enc,&output_dec,&valid);
			mask = mask<<1;
			printf("Input Data: %d, Output Data: %d, Valid: %d\n",int(i),int(output_dec),int(valid));
		}
	}




//	for ( i=0 ; i <8 ; i++)
//	{
//		cout<<i<<": "<<int(mask) <<" ^ "<<int(data_in)<<" = "<<int(mask^data_in)<<"\n";//<<"  "<<mask <<"\n";
//		ecc_decoder(data_in^mask,ecc_in, &output, &valid);
//		printf("output = %d , valid = %d\n",int(output), int(valid));
//		if(valid==0)
//		{
//			return 1;
//		}
//		mask = mask<<1;
//		cout<<"\n\n";
//	}

	return 0;
}
