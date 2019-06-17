/*Copyright (c) 2016 CareerMonk Publications and others.
#E-Mail            : info@careermonk.com 
#Creation Date     : 2008-01-10 06:15:46 
#Created by        : Narasimha Karumanchi 
#Book Title        : Data Structures And Algorithms Made Easy
#Warranty          : This software is provided "as is" without any 
#                    warranty; without even the implied warranty of 
#                    merchantability or fitness for a particular purpose.*/

#include<stdio.h>
#include <ctype.h>

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

int peek(struct Stack *S){
    /* S->top == - 1 indicates empty stack*/
    if(isEmpty(S)){	
        printf("Stack is Empty");
        return '\0';
    }
    else 
        return (S->array[S->top]); 
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

void deleteStack(struct Stack *S){
    if(S) {     
        if(S->array)  
             free(S->array);
                  free(S);
      }
}

int postfixEvaluation(char expression[]){ 
    // Create a Stack of capacity equal to expression size 
    struct Stack* stk = createStack(strlen(expression)); 
    int i; 

    // Scan all characters one by one 
    for (i = 0; expression[i]; ++i){ 
        // If the scanned character is an operand (number here), 
        // push it to the Stack. 
        if (isdigit(expression[i])) 
            push(stk, expression[i] - '0'); 
  
        // If the scanned character is an operator, pop top two 
        // elements from stack apply the operator 
        else{ 
            int topElement = pop(stk); 
            int secondTopElement = pop(stk); 
            switch (expression[i]){ 
                case '+': push(stk, secondTopElement + topElement); break; 
                case '-': push(stk, secondTopElement - topElement); break; 
                case '*': push(stk, secondTopElement * topElement); break; 
                case '/': push(stk, secondTopElement/topElement); break; 
            } 
        } 
    } 
    return pop(stk); 
} 
  
// test code
int main() {
    printf ("postfix evaluation: %d", postfixEvaluation("123*+5-")); 
    return 0; 
} 
