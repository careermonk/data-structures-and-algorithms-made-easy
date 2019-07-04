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

void bubbleSortImproved(int data[], int size) {
    int pass, i, temp, swapped = 1;
    for (pass = size - 1; pass >= 0 && swapped; pass--) {
        swapped = 0;
        for (i = 0; i <= pass - 1 ; i++) {
            if(data[i] > data[i+1]) {
                // swap elements
                temp = data[i];
                data[i] = data[i+1];
                data[i+1] =  temp;
                swapped = 1;
            }
        }
    }
}

void bubbleSort(int data[], int size){
    for(int step=0; step<size-1; ++step){
        for(int i=0; i<size-step-1; ++i){
            // To sort in descending order, change > to <.
            if (data[i]>data[i+1]){
                int temp = data[i];
                data[i] = data[i+1];
                data[i+1]= temp;
            }
        }
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
    bubbleSortImproved(data, size);
    printf("Sorted array in ascending order:\n");
    printArray(data, size);
}
