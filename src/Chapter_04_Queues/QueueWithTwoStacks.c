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

struct Queue {
    struct Stack *S1;        // for enQueue
    struct Stack *S2;        // for deQueue
};

int queueSize(struct Queue *Q) {
    return size(Q->S1);
}

struct Queue *createQueue(int capacity) {
    struct Stack *S1 = createStack(capacity);
    struct Stack *S2 = createStack(capacity);
    struct Queue *Q = malloc(sizeof(struct Queue));
    if(!Q)
        return NULL;
    Q->S1 = S1;
    Q->S2 = S2;
    return Q;
}

void enQueue(struct Queue *Q, int data) {
    push(Q->S1, data);
}

int deQueue(struct Queue *Q) {
    if(!isEmpty(Q->S2))
        return pop(Q->S2);
    else {
        while( !isEmpty(Q->S1) )
            push(Q->S2, pop(Q->S1));
        return pop(Q->S2);
    }
}

void deleteQueue(struct Queue *Q){
    if(Q) {
        if(Q->S1)
             free(Q->S1);
      if(Q->S2)
        free(Q->S2);
                  free(Q);
      }
}

int main(){
    // Initializing Queue
    struct Queue *Q;
    Q = createQueue(6);

    // Adding elements in Queue
    enQueue(Q, 1);
    enQueue(Q, 3);
    enQueue(Q, 7);
    enQueue(Q, 5);
    enQueue(Q, 10);
    enQueue(Q, 19);

    // Printing size of Queue
    printf("\nSize of queue : %d\n", queueSize(Q));

    // Removing Element from Queue
    printf("\nDequeued element : %d\n", deQueue(Q));
    printf("Dequeued element : %d\n", deQueue(Q));
    printf("Dequeued element : %d\n", deQueue(Q));
    printf("Dequeued element : %d\n", deQueue(Q));
    printf("Dequeued element : %d\n", deQueue(Q));
    printf("Dequeued element : %d\n", deQueue(Q));

    // Removing Queue
    deleteQueue(Q);
    return 0;
}
