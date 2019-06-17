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
#include <string.h>
#include <limits.h>

struct MultiStacks {
    int top1, top2;
    int capacity;
    char *array;
};

struct MultiStacks *createStack(int capacity) {
    struct MultiStacks *twoStacks = malloc(sizeof(struct MultiStacks));
    if(!twoStacks) 
        return NULL;
    twoStacks->capacity = capacity;
    twoStacks->top1 = -1;
    twoStacks->top2 = capacity;
    twoStacks->array= malloc(twoStacks->capacity * sizeof(int));
    if(!twoStacks->array) 
        return NULL;
    return twoStacks;
}

int isEmpty(struct MultiStacks *twoStacks, int stackNumber) {
    if (stackNumber == 1){
        return (twoStacks->top1 == -1);
    } else {
        return (twoStacks->top2 == twoStacks->capacity);
    }
}

int size(struct MultiStacks *twoStacks, int stackNumber) {
    if (stackNumber == 1){
        return (twoStacks->top1 + 1);
    } else {
        return (twoStacks->capacity - twoStacks->top2);
    }
}

int isFull(struct MultiStacks *twoStacks){
    return (size(twoStacks, 1) + size(twoStacks, 2) == twoStacks->capacity);
}

void push(struct MultiStacks *twoStacks, int stackNumber, char data){
    if(isFull(twoStacks)){
        printf("Stack overflow\n");
        return;
    }
    if (stackNumber == 1){
        twoStacks->array[++twoStacks->top1] = data;
    } else {
        twoStacks->array[--twoStacks->top2] = data;
    }
}

char pop(struct MultiStacks *twoStacks, int stackNumber){
    /* twoStacks->top == - 1 indicates empty stack*/
    if(isEmpty(twoStacks, stackNumber)){	
        printf("Stack is Empty\n");
        return '\0';
    }
    if (stackNumber == 1){
        return (twoStacks->array[twoStacks->top1--]); 
    } else {
        return (twoStacks->array[twoStacks->top2++]); 
    }
}

int peek(struct MultiStacks *twoStacks, int stackNumber){
    if(isEmpty(twoStacks, stackNumber)){	
        printf("Stack is Empty");
        return INT_MIN;;
    }
    if (stackNumber == 1){
        return (twoStacks->array[twoStacks->top1]); 
    } else {
        return (twoStacks->array[twoStacks->top2]); 
    }
}

void deleteStack(struct MultiStacks *twoStacks){
    if(twoStacks) {     
        if(twoStacks->array)  
             free(twoStacks->array);
                  free(twoStacks);
      }
}

int main(void){
    int i = 0, capacity = 15;
    // create a stack of capacity 15
    struct MultiStacks *stk = createStack(capacity);

    for(i = 0; i <= capacity; i++){
    	printf("Pushing %d to %d\n", i, i%2+1);
        push(stk, i%2+1, i);
    }
    printf("Top element in first stack is %d\n", peek(stk, 1));
    printf("Top element in second stack is %d\n", peek(stk, 2));
    printf("Size of first stack is %d\n", size(stk,1));
    printf("Size of second stack is %d\n", size(stk,2));

    for (i = 0; i <= capacity; i++){
        printf("Popped element from stack %d is %d\n", i%2+1, pop(stk, i%2+1));
    }
    deleteStack(stk);
    return 0;
}

