int any_odd_one(unsigned x){
	return x&0xAAAAAAAA; //0x55555555 is 01010101.... for 32 bits
}