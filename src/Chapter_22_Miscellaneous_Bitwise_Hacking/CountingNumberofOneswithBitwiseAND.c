/*Copyright (c) 2016 CareerMonk Publications and others.
#E-Mail            : info@careermonk.com 
#Creation Date     : 2008-01-10 06:15:46 
#Created by        : Narasimha Karumanchi 
#Book Title        : Data Structures And Algorithms Made Easy
#Warranty          : This software is provided "as is" without any 
#                    warranty; without even the implied warranty of 
#                    merchantability or fitness for a particular purpose.*/

#include<stdio.h>

int countingNumberofOneswithBitwiseAND(unsigned int n){
    int count =0;
    while(n){
        if(n&1){
            count++;
        }
        n=n>>1;
    }
    return count;
}
void countingNumberofOneswithBitwiseAND_test(){
    int i=10;
    printf("Number of one's in %d is/are %d\n",i, countingNumberofOneswithBitwiseAND(i));
    i = 5;
    printf("Number of one's in %d is/are %d\n",i, countingNumberofOneswithBitwiseAND(i));
    i = 100;
    printf("Number of one's in %d is/are %d\n",i, countingNumberofOneswithBitwiseAND(i));
    i = 1;
    printf("Number of one's in %d is/are %d\n",i, countingNumberofOneswithBitwiseAND(i));
    i = 0;
    printf("Number of one's in %d is/are %d\n",i, countingNumberofOneswithBitwiseAND(i));    
}
