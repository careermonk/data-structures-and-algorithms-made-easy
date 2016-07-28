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
#include <limits.h>

struct DynArrayStack {
    int top;
    int capacity;
    int *array;
};

struct DynArrayStack *CreateStack(){
    struct DynArrayStack *S = malloc(sizeof(struct DynArrayStack));  
    if(!S) 
     return NULL;
    S->capacity = 1;
    S->top = -1;
    S->array = malloc(S->capacity * sizeof(int));	// allocate an array of size 1 initially

    if(!S->array) 
        return NULL;
    return S;
}

int IsFullStack(struct DynArrayStack *S){
    return (S->top == S->capacity-1);
}

void DoubleStack(struct DynArrayStack *S){
    S->capacity *= 2;
    S->array = realloc(S->array, S->capacity * sizeof(int));
}

void Push(struct DynArrayStack *S, int x){
    // No overflow in this implementation
    if(IsFullStack(S))   
     DoubleStack(S); 

    S->array[++S->top] = x;
}

int IsEmptyStack(struct DynArrayStack *S){
    return S->top == -1;
}

int Top(struct DynArrayStack *S){
    if(IsEmptyStack(S))     
     return INT_MIN;

    return S->array[S->top];
}

int Pop(struct DynArrayStack *S){
    if(IsEmptyStack(S))    
     return INT_MIN;

    return S->array[S->top--];
}

void DeleteDynStack(struct DynArrayStack *S){
    if(S) {
        if(S->array) 
            free(S->array);
        free(S);
    }
}

void testDynamicStack(){
    struct DynArrayStack *s = CreateStack();
    Push(s, 10);
    Push(s, 1);
    Push(s, 11);
    Push(s, 2);
    Push(s, 10);
    Push(s, 50);
    while(!IsEmptyStack(s)){
        printf("%d\n", Pop(s));
    }
    DeleteDynStack(s);
}