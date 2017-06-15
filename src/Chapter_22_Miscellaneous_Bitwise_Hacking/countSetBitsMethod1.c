#include<stdio.h>
 
/* Code to find the number of 1s in binary
   representation of an integer. */
unsigned int countSetBitsMethod1(int n){
    unsigned int count = 0;
    while (n) {
      n &= (n-1) ;
      count++;
    }
    return count;
}
 
/* Test Code */
int main(){
    int i = 5;
    printf("Number of 1s in %d are %d", i, countSetBitsMethod1(i));
    return 0;
}
