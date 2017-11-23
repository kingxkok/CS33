long loop(long x, long n){
	long result = 0;
	long mask;
	for(mask = 1; mask != 0; mask = mask << n&0xFF){
		result |= mask&x;
	}
	return result;
}

/**
	A. x is %rdi, n is %rsi, result in %rax, mask in %rdx
	B. result 0, mask 1
	C. mask is not 0
	D. mask gets mask shifted left by the 8 Least significant bits of n
	E. result becomes result or'ed with mask&x
	F. Done
*/
