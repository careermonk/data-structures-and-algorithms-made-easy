#include <stdio.h>
//Note: i and j indicates the position of bits from right to left starting with 1
int swapbits(int n, int i, int j){
	// We can simply use the XOR operator to toggle the bits.
	n ^= (1 << i-1);
	n ^= (1 << j-1);
	return n;
}
int main(void) {
	int num = 34;  //Binary Number: 00100010
	int i = 3, j = 6;
	printf ("\nGiven Number: %d", num);
	printf ("\nBinary representation of given number: 00100010");
	num = swapbits (num, i, j);
	printf ("\nGiven Number after swapping %d and %d bits: %d", i, j, num);
	return 0;
}
