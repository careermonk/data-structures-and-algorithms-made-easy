// Copyright (c) 2008 CareerMonk Publications and others.
// #E-Mail          : info@careermonk.com
// Creation Date    : 2008-01-10 06:15:46
// Created by       : Narasimha Karumanchi
// Book Title       : Data Structures And Algorithms Made Easy
// Warranty         : This software is provided "as is" without any
//                    warranty; without even the implied warranty of
//                    merchantability or fitness for a particular purpose.

#include <stdio.h>
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

int isEmptyStack(struct Stack *S) {
    return (S->top == -1);  	// if the condition is true then 1 is returned else 0 is returned
}

int stackSize(struct Stack *S) {
    return (S->top + 1);
}

int isFullStack(struct Stack *S){
    //if the condition is true then 1 is returned else 0 is returned
    return (S->top == S->capacity - 1);
}

void doubleStack(struct Stack *S){
    S->capacity *= 2;
    S->array = realloc(S->array, S->capacity * sizeof(int));
}


void push(struct Stack *S, int data){
    if(isEmptyStack(S))
        doubleStack(S);
    S->array[++S->top] = data;
}

int pop(struct Stack *S){
    /* S->top == - 1 indicates empty stack*/
    if(isEmptyStack(S)){
        printf("Stack is Empty\n");
        return INT_MIN;
    }
    else /* Removing element from  ‘top’ of the array and reducing ‘top’ by 1*/
        return (S->array[S->top--]);
}

int peek(struct Stack *S){
    /* S->top == - 1 indicates empty stack*/
    if(isEmptyStack(S)){
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
     int front, rear;
     int capacity;
     int size;
     int *array;
};

// Create an empty queue
struct Queue *createQueue(int capacity) {
     struct Queue *Q = malloc(sizeof(struct Queue));
     if(!Q)
          return NULL;
     Q->capacity = capacity;
     Q->front = Q->rear = -1;
     Q->size = 0;
     Q->array= malloc(Q->capacity * sizeof(int));

     if(!Q->array)
          return NULL;
     return Q;
}

// Returns queue size
int queueSize(struct Queue *Q) {
    return Q->size;
}

// Returns Frnt Element of the Queue
int frontElement(struct Queue *Q) {
    return Q->array[Q->front];
}

// Returns the Rear Element of the Queue
int rearElement(struct Queue *Q) {
    return Q->array[Q->rear];
}

// Check's if Queue is empty or not
int isEmptyQueue(struct Queue *Q) {
     // if the condition is true then 1 is returned else 0 is returned
     return (Q->size == 0);
}

// Check's if Queue is full or not
int isFullQueue(struct Queue *Q) {
     // if the condition is true then 1 is returned else 0 is returned
     return (Q->size == Q->capacity);
}

void resizeQueue(struct Queue *Q) {
    int size = Q->capacity;
    Q->capacity = Q->capacity*2;
    Q->array = realloc (Q->array, sizeof(int) * Q->capacity);
    if(!Q->array) {
        printf("Memory Error");
        return;
    }
    if(Q->front > Q->rear ) {
        for(int i=0; i < Q->front; i++) {
            Q->array[i+size] =Q->array[i];
        }
        Q->rear = Q->rear + size;
    }
}


// Adding elements in Queue
void enqueue(struct Queue *Q, int data) {
    if(isFullQueue(Q))
        resizeQueue(Q);
    Q->rear = (Q->rear+1) % Q->capacity;
    Q->array[Q->rear]= data;
    if(Q->front == -1)
        Q->front = Q->rear;
    Q->size += 1;
}

// Removes an element from front of the queue
int dequeue(struct Queue *Q) {
    int data = INT_MIN; //or element which does not exist in Queue
    if(isEmptyQueue(Q)){
        printf("Queue is empty\n");
        return data;
    }
    data = Q->array[Q->front];
    if(Q->front == Q->rear) {
        Q->front = Q->rear = -1;
        Q->size = 0;
    } else {
        Q->front = (Q->front+1) % Q->capacity;
        Q->size -= 1;
    }
    return data;
}

void deleteQueue(struct Queue *Q) {
    if(Q) {
        if(Q->array)
            free(Q->array);
        free(Q);
    }
}

void reverseQueue(struct Queue *Q) {
    struct Stack *S = createStack(5);
    while (!isEmptyQueue(Q))
        push(S, dequeue(Q));
    while (!isEmptyStack(S))
        enqueue(Q, pop(S));
}


int main() {
    // Initializing Queue
    struct Queue *Q;
    Q = createQueue(3);

    // Adding elements in Queue
    enqueue(Q, 1);
    enqueue(Q, 3);
    enqueue(Q, 7);
    enqueue(Q, 5);
    enqueue(Q, 10);
    enqueue(Q, 19);

    // Printing size of Queue
    printf("\nSize of queue : %d\n", queueSize(Q));

    // Printing front and rear element of Queue */
    printf("Front element : %d\n", frontElement(Q));
    printf("Rear element : %d\n", rearElement(Q));

    reverseQueue(Q);

    // Printing size of Queue
    printf("\nSize of queue : %d\n", queueSize(Q));

    // Printing front and rear element of Queue */
    printf("Front element : %d\n", frontElement(Q));
    printf("Rear element : %d\n", rearElement(Q));

    // Removing Element from Queue
    printf("\nDequeued element : %d\n", dequeue(Q));
    printf("Dequeued element : %d\n", dequeue(Q));
    printf("Dequeued element : %d\n", dequeue(Q));
    printf("Dequeued element : %d\n", dequeue(Q));
    printf("Dequeued element : %d\n", dequeue(Q));
    printf("Dequeued element : %d\n", dequeue(Q));
    // Removing Queue
    deleteQueue(Q);
    return 0;
}
