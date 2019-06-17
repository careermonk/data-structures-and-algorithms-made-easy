/*Copyright (c) 2016 CareerMonk Publications and others.
#E-Mail            : info@careermonk.com 
#Creation Date     : 2008-01-10 06:15:46 
#Created by        : Narasimha Karumanchi 
#Book Title        : Data Structures And Algorithms Made Easy
#Warranty          : This software is provided "as is" without any 
#                    warranty; without even the implied warranty of 
#                    merchantability or fitness for a particular purpose.*/

#include<stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Stack {
    int top;
    int capacity;
    int *array;
};

struct Stack *createStack(int capacity) {
    struct Stack *S = malloc(sizeof(struct Stack));
    if(!S) 
        return NULL;
    S->capacity = capacity;
    S->top = -1;
    S->array= malloc(S->capacity * sizeof(int));
    if(!S->array) 
        return NULL;
    return S;
}

int isEmpty(struct Stack *S) {
    return (S->top == -1);  	// if the condition is true then 1 is returned else 0 is returned
}

int size(struct Stack *S) {
    return (S->top + 1);  
}

int isFull(struct Stack *S){
    //if the condition is true then 1 is returned else 0 is returned
    return (S->top == S->capacity - 1); 
}

void doubleStack(struct Stack *S){
    S->capacity *= 2;
    S->array = realloc(S->array, S->capacity * sizeof(int));
}


void push(struct Stack *S, int data){
    if(isFull(S)) 
        doubleStack(S); 
    S->array[++S->top] = data;   
}

int pop(struct Stack *S){
    /* S->top == - 1 indicates empty stack*/
    if(isEmpty(S)){	
        printf("Stack is Empty\n");
        return INT_MIN;
    }
    else /* Removing element from  ‘top’ of the array and reducing ‘top’ by 1*/
        return (S->array[S->top--]); 
}

int peek(struct Stack *S){
    /* S->top == - 1 indicates empty stack*/
    if(isEmpty(S)){	
        printf("Stack is Empty");
        return INT_MIN;;
    }
    else 
        return (S->array[S->top]); 
}

void deleteStack(struct Stack *S){
    if(S) {     
        if(S->array)  
             free(S->array);
                  free(S);
      }
}
struct AdvancedStack {
     struct Stack *elementStack;
     struct Stack *minStack;
};


int isEmptyA(struct AdvancedStack *S) {
    return (S->elementStack->top == -1);  	// if the condition is true then 1 is returned else 0 is returned
}

int sizeA(struct AdvancedStack *S) {
    return (S->elementStack->top + 1);  
}

int isFullA(struct AdvancedStack *S){
    //if the condition is true then 1 is returned else 0 is returned
    return (S->elementStack->top == S->elementStack->capacity - 1); 
}

void pushA(struct AdvancedStack *S, int data){
	push(S->elementStack, data);
	
	if(isEmpty(S->minStack) || peek(S->minStack) >= data)
		push(S->minStack, data);

}

int popA(struct AdvancedStack *S ){
	int temp;
	if(isEmpty(S->elementStack)) 
		return -1;
	
	temp = peek(S->elementStack);
	if(peek(S->minStack) == pop(S->elementStack))
		pop(S->minStack);
	return temp;
}

int peekA(struct AdvancedStack *S ){
    return peek(S->elementStack);
}

int getMinimum(struct AdvancedStack *S){
     return peek(S->minStack);
}

struct AdvancedStack * createAdvancedStack(int capacity){
     struct AdvancedStack *S = malloc (sizeof (struct AdvancedStack));

     if(!S) 
          return NULL;

     S->elementStack = createStack(capacity);
     S->minStack = createStack(capacity);
     return S;
}

void deleteStackA(struct AdvancedStack *S){
	if(S) {     
		deleteStackA(S->elementStack);
		deleteStackA(S->minStack);
		free(S);
	}
}

int main(){
    int i = 0, capacity = 5;
    // create a stack of capacity 5
    struct AdvancedStack *stk = createAdvancedStack(capacity);

    for(i = 0; i <= 2 * capacity; i++){
        pushA(stk, (7*i)%4);
    }

    printf("Top element is %d\n", peekA(stk));
    printf("Stack size is %d\n", sizeA(stk));

    for (i = 0; i <= capacity; i++){
        printf("Popped element is %d\n", popA(stk));
        printf("Minimum element is %d\n", getMinimum(stk));
    }

    if (isEmptyA(stk))
        printf("Stack is empty");
    else
        printf("Stack is not empty");

    deleteStackA(stk);
    return 0;
}
