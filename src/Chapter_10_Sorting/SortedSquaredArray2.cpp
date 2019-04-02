/*Copyright (c) 2016 CareerMonk Publications and others.
#E-Mail            : info@careermonk.com 
#Creation Date     : 2008-01-10 06:15:46 
#Created by        : Narasimha Karumanchi 
#Book Title        : Data Structures And Algorithms Made Easy
#Warranty          : This software is provided "as is" without any 
#                    warranty; without even the implied warranty of 
#                    merchantability or fitness for a particular purpose.*/

#include<bits/stdc++.h> 
using namespace std; 
void sortedSquaredArray(int A[], int n) {
    int result[n];
    int j = 0;
    // Find the last index of the negative numbers
    while (j < n && A[j] < 0)
        j++;

    // i points to the last index of negative numbers
    int i = j-1;

    int t = 0;
    // j points to the first index of the positive numbers
    while (i >= 0 && j < n) {
        if (A[i] * A[i] < A[j] * A[j]) {
            result[t++] = A[i] * A[i];
            i--;
        } else {
            result[t++] = A[j] * A[j];
            j++;
        }
    }
    // add the remaining negative numbers squares to result
    while (i >= 0) {
        result[t++] = A[i] * A[i];
        i--;
    }

    // add the remaining positive numbers squares to result
    while (j < n) {
        result[t++] = A[j] * A[j];
        j++;
    }
    cout << "\nSorted squares array " << endl; 
    for (int i = 0 ; i < n ; i++) 
        cout << result[i] << " " ; 
}

int main(){ 
    int A[] = { -4, -3, -1, 3, 4, 5 }; 
    int n = sizeof(A)/sizeof(A[0]); 

    cout << "Given sorted array " << endl; 
    for (int i = 0; i < n; i++) 
        cout << A[i] << " " ; 
    sortedSquaredArray(A, n); 
    return 0; 
}
