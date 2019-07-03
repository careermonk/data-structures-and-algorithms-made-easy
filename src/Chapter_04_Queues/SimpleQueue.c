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
int size(struct Queue *Q) {
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
int isEmpty(struct Queue *Q) {
     // if the condition is true then 1 is returned else 0 is returned
     return (Q->size == 0);
}

// Check's if Queue is full or not
int isFull(struct Queue *Q) {
     // if the condition is true then 1 is returned else 0 is returned
     return (Q->size == Q->capacity);
}

// Adding elements in Queue
void enqueue(struct Queue *Q, int data) {
    if(isFull(Q))
        printf("Queue overflow\n");
    else {
        Q->rear = (Q->rear+1) % Q->capacity;
        Q->array[Q->rear]= data;
        if(Q->front == -1)
            Q->front = Q->rear;
        Q->size += 1;
    }
}

// Removes an element from front of the queue
int dequeue(struct Queue *Q) {
    int data = INT_MIN; //or element which does not exist in Queue
    if(isEmpty(Q)){
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

int main() {
    // Initializing Queue
    struct Queue *Q;
    Q = createQueue(4);
    // Adding elements in Queue
    enqueue(Q, 1);
    enqueue(Q, 3);
    enqueue(Q, 7);
    enqueue(Q, 5);
    enqueue(Q, 10);

    // Printing size of Queue
    printf("\nSize of queue : %d\n", size(Q));

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
    enqueue(Q, 15);
    enqueue(Q, 100);

    // Printing size of Queue
    printf("\nSize of queue : %d\n", size(Q));

    // Printing front and rear element of Queue
    printf("Front element : %d\n", frontElement(Q));
    printf("Rear element : %d\n", rearElement(Q));

    // Removing Queue
    deleteQueue(Q);
    return 0;
}

