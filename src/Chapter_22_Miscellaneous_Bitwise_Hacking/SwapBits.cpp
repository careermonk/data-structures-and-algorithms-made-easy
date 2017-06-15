#include <iostream>
#include <bitset>
using namespace std;

//Note: i and j indicates the position of bits from right to left starting with 1
int swapbits(int n, int i, int j){
	// We can simply use the XOR operator to toggle the bits.
	n ^= (1 << i-1);
	n ^= (1 << j-1);
	return n;
}

int main() {
	int num = 34;  //Binary Number: 00100010
	int i = 3, j = 6;
	cout << "Given Number: " << num << endl;
	cout << "Binary representation of given number: 00100010" << endl;
	num = swapbits (num, i, j);
	cout << "Given Number after swapping " << i <<" and " << j << " bits: " << num << endl;
	
	return 0;
}
