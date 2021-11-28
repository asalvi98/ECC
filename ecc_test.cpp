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
	data_8 in_data = 0b11101010;
	for (int i=0 ; i < 256 ; i++)
	{
		in_data = i;
		ecc_encoder(in_data, &o);
		int temp_print = o;
		cout<<i << " " <<temp_print << "\n";

	}



	return 0;
}
