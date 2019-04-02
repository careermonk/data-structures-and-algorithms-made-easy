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
    for (int i = 0; i < n; ++i)
        result[i] = A[i] * A[i];

    sort(result, result+n);

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
