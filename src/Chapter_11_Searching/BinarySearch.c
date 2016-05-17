/*Copyright (c) 2016 CareerMonk Publications and others.
#E-Mail            : info@careermonk.com 
#Creation Date     : 2008-01-10 06:15:46 
#Created by        : Narasimha Karumanchi 
#Book Title        : Data Structures And Algorithms Made Easy
#Warranty          : This software is provided "as is" without any 
#                    warranty; without even the implied warranty of 
#                    merchantability or fitness for a particular purpose.*/

#include <stdio.h>
#include <stdlib.h>

//Iterative Binary Search Algorithm
int binarySearchIterative(int A[], int n, int data) {
    int mid;
    int low =  0;
    int high = n-1;
    while (low <= high) {
        mid  = low + (high-low)/2; //To avoid overflow
        if(A[mid] == data)
            return mid;
        else if(A[mid] < data)
            low =  mid + 1;
        else high =  mid - 1;
    }
    return -1;
}

//Recursive Binary Search Algorithm
int binarySearchRecursive(int A[], int low, int high, int data) {
    int mid  = low + (high-low)/2; //To avoid overflow
    if (low>high)
        return -1;
    if(A[mid] == data)
        return mid;
    else if(A[mid] < data)
        return binarySearchRecursive (A, mid + 1, high, data);
    else 	return binarySearchRecursive (A, low, mid - 1 , data);
    return -1;
}

void binarySearch_test(){
    int n, data, A[10]={3,6,19,25,33,39,55,78,99,100};
    n =10;
    data =20;
    printf("\nElement %d is at location: %d (-1 indicates not present in array)", data, binarySearchIterative(A, n, data));
    printf("\nElement %d is at location: %d (-1 indicates not present in array)", data, binarySearchRecursive(A, 0, n-1, data));
    data =39;
    printf("\nElement %d is at location: %d (-1 indicates not present in array)", data, binarySearchIterative(A, n, data));
    printf("\nElement %d is at location: %d (-1 indicates not present in array)", data, binarySearchRecursive(A, 0, n-1, data));

}

