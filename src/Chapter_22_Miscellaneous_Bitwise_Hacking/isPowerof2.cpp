#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isPowerof2(int n){
	if(!(n&(n-1)))
		return true;
	else
		return false;
}
int main() {
	int n=32;
	cout<<n<<" is power of 2:"<<isPowerof2(n)<<endl;
	n=15;
	cout<<n<<" is power of 2:"<<isPowerof2(n)<<endl;
	return 0;
}
