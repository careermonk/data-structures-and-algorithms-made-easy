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

struct Stack {
    int top;
    int capacity;
    char *array;
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


void push(struct Stack *S, char data){
    if(isFull(S)) 
        doubleStack(S); 
    S->array[++S->top] = data;   
}

char pop(struct Stack *S){
    /* S->top == - 1 indicates empty stack*/
    if(isEmpty(S)){	
        printf("Stack is Empty\n");
        return '\0';
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

void reverseStack(struct Stack *S){
    char data;

    if(isEmpty(S)) 
        return;

    data = pop(S);
    reverseStack(S);
    insertAtBottom(S, data);
}

void insertAtBottom(struct Stack *S, char data){
    char temp;

    if(isEmpty(S)) {
       push(S, data);
       return;
    }

    temp = pop(S);
    insertAtBottom(S, data);
    push(S, temp);
}


int main(void){
    int i = 0, capacity = 2;
    // create a stack of capacity 2
    struct Stack *stk = createStack(capacity);

    for(i = 0; i <= capacity; i++){
        push(stk, i);
    }
    reverseStack(stk);
    printf("Top element is %d\n", peek(stk));
    printf("Stack size is %d\n", size(stk));

    for (i = 0; i <= capacity; i++){
        printf("Popped element is %d\n", pop(stk));
    }

    deleteStack(stk);
    return 0;

    return 0;
}

