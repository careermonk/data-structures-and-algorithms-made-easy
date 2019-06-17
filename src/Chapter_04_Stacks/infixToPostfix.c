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
#include <string.h>
#include <ctype.h>

struct stack {
    int top;
    int capacity;
    int *array;
};

struct stack *createStack(int capacity) {
    struct stack *S = malloc(sizeof(struct stack));
    if(!S) 
        return NULL;
    S->capacity = capacity;
    S->top = -1;
    S->array= malloc(S->capacity * sizeof(int));
    if(!S->array) 
        return NULL;
    return S;
}

int isEmpty(struct stack *S) {
    return (S->top == -1);  	// if the condition is true then 1 is returned else 0 is returned
}

int isFull(struct stack *S){
    //if the condition is true then 1 is returned else 0 is returned
    return (S->top == S->capacity - 1); 
}

void doubleStack(struct stack *S){
    S->capacity *= 2;
    S->array = realloc(S->array, S->capacity * sizeof(int));
}

void push(struct stack *S, char data){
    if(isFull(S)) 
        doubleStack(S); 
    S->array[++S->top] = data;   
}

int peek(struct stack *S){
    /* S->top == - 1 indicates empty stack*/
    if(isEmpty(S)){	
        printf("Stack is Empty");
        return '\0';
    }
    else 
        return (S->array[S->top]); 
}

char pop(struct stack *S){
    /* S->top == - 1 indicates empty stack*/
    if(isEmpty(S)){	
        printf("Stack is Empty\n");
        return '\0';
    }
    else /* Removing element from  ‘top’ of the array and reducing ‘top’ by 1*/
        return (S->array[S->top--]); 
}

void deleteStack(struct stack *S){
    if(S) {     
        if(S->array)  
             free(S->array);
                  free(S);
      }
}

int priority(char x){
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
}
 
int infixToPostfix(char expression[]){
        char *e, x;
		// create a stack of capacity 5
		struct stack *stk = createStack(5);

    e = expression;
    while(*e != '\0'){
        if(isalnum(*e))
            printf("%c",*e);
        else if(*e == '(')
            push(stk, *e);
        else if(*e == ')'){
            while((x = pop(stk)) != '(')
                printf("%c", x);
        }
        else{
            while(priority(peek(stk)) >= priority(*e))
                printf("%c",pop(stk));
            push(stk, *e);
        }
        e++;
    }
    while(!isEmpty(stk)){
        printf("%c",pop(stk));
    }
}

int main(){
      infixToPostfix("(a+(b*(d+2)))");
}
