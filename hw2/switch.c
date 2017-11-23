long switch_prob(long x, long n){
	long result = x;
	switch(n){  //n in rsi
		/* code to fill */
		//jump if n>65
		//jump above does work if negative since negative is big number
		//ja is unsigned
		case 60:
		case 62:
			result = 8*x;
		break;
		//61 is same as default

		case 63:
			result = x>>3;
		break;
		case 64:
			result = x<<4-x;
			x = result;
		case 65:
			x*=x;
		default:
			result = 75+x;
	}
	return result;
}