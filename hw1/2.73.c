#include <limits.h>

int saturating_add(int x, int y){

	long long xl = (long long) x;
	long long yl = (long long) y;
	long long sum = xl + yl;
	
	int overflowPositive = (sum & 0x880000000L) == 0x0080000000L; //1 means overflow positive
	int overflowNegative = (sum & 0x880000000L) == 0x0800000000L; //leftmost one means negative, but 0 right after means it's less than INT_MIN

	return (!(overflowPositive||overflowNegative))*(x+y)+overflowNegative*(INT_MIN)+overflowPositive*(INT_MAX);
	//if either overflow, ignore sum

}