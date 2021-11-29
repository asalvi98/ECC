#include<stdio.h>
#include<iostream>
#include"ap_fixed.h"
#include"ap_int.h"
#include"ecc.h"


using namespace::std;

//int main()
//{data_ecc o;
//	ecc(0b11101010, &o);
//	return 0;
//}
int main()
{ 	data_5 o;
	data_8 output;
	data_8 output_1;
//	data_8 in_data = 0b11101010;

//	data_8 data_in = 0b11101000;
//	data_5 ecc_in = 0b11111;
	data_8 data_in = 0b00000111;
	data_5 ecc_in = 0b10000;
//	for (int i=0 ; i < 256 ; i++)
//	{
//		in_data = i;
//		ecc_encoder(in_data, &o);
//		int temp_print = o;
//		cout<<i << " " <<temp_print << "\n";
//
//	}
	data_8 mask = 0b00000101;
	data_1 valid;
	int i=0;
	for ( i=0 ; i <8 ; i++)
	{
		cout<<i<<": "<<int(mask) <<" ^ "<<int(data_in)<<" = "<<int(mask^data_in)<<"\n";//<<"  "<<mask <<"\n";
		ecc_decoder(data_in^mask,ecc_in, &output, &valid);
		printf("output = %d , valid = %d\n",int(output), int(valid));
		if(valid==0)
		{
			return 1;
		}
		mask = mask<<1;
		cout<<"\n\n";
	}

//			printf("%d \n",int(5));
//			ecc_decoder(5,ecc_in, &output);
//			printf("%d \n",int(output));
//			mask = mask <<1;
//			printf("\n\n");
//			printf("%d \n",int(3));
//			ecc_decoder(3,ecc_in, &output_1);
//			printf("%d \n",int(output_1));

	return 0;
}
