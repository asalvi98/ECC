int pattern[5];
ap_fixed<8> pattern_0;
pattern_0 = 0b111110000;
pattern[1] = 0b110001110;
pattern[2] = 0b001101101;
pattern[3] = 0b101011011;
pattern[4] = 0b010110111;


typedef ap_fixed<64> data_in;
typedef ap_fixed<10> data_ecc;


void ecc(data_in data, data_ecc * ecc_bits) ;
