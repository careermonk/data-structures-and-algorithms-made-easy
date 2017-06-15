#include <iostream>
#include <bitset>
using namespace std;

int main(){
    long num, decimal_num, remainder, base = 1, binary = 0;
 
    num = 34;
    decimal_num = num;
    while (num > 0){
        remainder = num % 2;
        binary = binary + remainder * base;
        num = num / 2;
        base = base * 10;
    }
    cout<<"Given number is = "<< decimal_num << endl;
    cout<<"Its binary equivalent is = "<< binary <<endl;
    
    // Alternative using bitset
	cout<<"Given number is = "<< decimal_num << endl;
    cout<<"Its binary equivalent is = "<< bitset<8>(decimal_num) << endl;
    return 0;
}
