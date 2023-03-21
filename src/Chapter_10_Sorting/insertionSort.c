/*Copyright (c) 2008 CareerMonk Publications and others.
#E-Mail            : info@careermonk.com
#Creation Date     : 2008-01-10 06:15:46
#Created by        : Narasimha Karumanchi
#Book Title        : Data Structures And Algorithms Made Easy
#Warranty          : This software is provided "as is" without any
#                    warranty; without even the implied warranty of
#                    merchantability or fitness for a particular purpose.*/

// Bubble Sort in C
#include <stdio.h>

void insertionSort(int data[], int size) {
    int i, j, key;
    for (i = 1; i <= size - 1; i++) {
        key = data[i];
        j = i;
        while (j >= 1 && data[j-1] > key) {
            data[j] = data[j-1];
            j--;
        }
        data[j] = key;
    }
}


void printArray(int data[], int size){
    for(int i=0; i<size; ++i){
        printf("%d  ", data[i]);
    }
    printf("\n");
}

int main(){
    int data[] = {-4, 35, 1, 10, -8};
    int size = sizeof(data)/sizeof(data[0]);
    insertionSort(data, size);
    printf("Sorted array in ascending order:\n");
    printArray(data, size);
}
