/*Copyright (c) 2016 CareerMonk Publications and others.
#E-Mail            : info@careermonk.com 
#Creation Date     : 2008-01-10 06:15:46 
#Created by        : Narasimha Karumanchi 
#Book Title        : Data Structures And Algorithms Made Easy
#Warranty          : This software is provided "as is" without any 
#                    warranty; without even the implied warranty of 
#                    merchantability or fitness for a particular purpose.*/
#include<stdio.h>
#include<stdlib.h>

int isPalindrome(char str[]){
    //the first index
    int i = 0;
    //the last index
    int j = strlen(str)-1;

    while(i < j && str[i] == str[j]){
        //increment start index and decrement last index
        i++;
        j--;
    }

    if(i < j){
        //did not reach the center
        printf("Not a palindrome\n");
        return 0;
    }
    else{
        //reached the center
        printf("Palindrome\n");
        return 1;
    }
}

int main(void){
    isPalindrome("ababaXababa");
    isPalindrome("ababababXbababbbbabba");
    return 0;
}
