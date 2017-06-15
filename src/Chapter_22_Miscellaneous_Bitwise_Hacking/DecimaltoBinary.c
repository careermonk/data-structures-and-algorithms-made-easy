#include <stdio.h>

void main(void){
    long num, remainder, base = 1, binary = 0;
 
    num = 1910;
    while (num > 0){
        remainder = num % 2;
        binary = binary + remainder * base;
        num = num / 2;
        base = base * 10;
    }
    printf("Given number is = %d\n", num);
    printf("Its binary equivalent is = %ld\n", binary);
}
