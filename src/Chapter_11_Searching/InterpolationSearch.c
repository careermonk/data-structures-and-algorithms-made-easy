/*Copyright (c) 2016 CareerMonk Publications and others.
#E-Mail            : info@careermonk.com 
#Creation Date     : 2008-01-10 06:15:46 
#Created by        : Narasimha Karumanchi 
#Book Title        : Data Structures And Algorithms Made Easy
#Warranty          : This software is provided "as is" without any 
#                    warranty; without even the implied warranty of 
#                    merchantability or fitness for a particular purpose.*/

#include <stdio.h>

int interpolationSearch(int A[], int n, int data) {
    int low = 0, mid, high = n-1;
    while (low <= high) {
        mid = low + (((data - A[low]) * (high - low))/(A[high] - A[low]));
        if (data == A[mid])
            return mid + 1;
        if (data < A[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
void interpolationSearch_test(){
    int n, data, A[10]={3,6,9,12,15,18,21,24,27,30};
    n =10;
    data =20;
    printf("\nElement %d is at location: %d (-1 indicates not present in array)", data, interpolationSearch(A, n, data));
    data =30;
    printf("\nElement %d is at location: %d (-1 indicates not present in array)", data, interpolationSearch(A, n, data));
}
