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

struct ListNode {
    int data;
    struct ListNode *next;
};

struct Queue {
    struct ListNode *front;
    struct ListNode *rear;
};

/* Create an empty queue */
struct Queue *CreateQueue() {
    struct Queue *Q;
    struct ListNode *temp;
    Q = malloc(sizeof(struct Queue));
    if(!Q)
         return NULL;

    temp = malloc(sizeof(struct ListNode));
    Q->front = Q->rear = NULL;
    return Q;
}

/* Returns queue size */
int size(struct Queue *Q) {
    struct ListNode *temp = Q->front;
    int count = 0;

    if(Q->front == NULL && Q->rear == NULL)
        return 0;

    while(temp != Q->rear){
        count++;
        temp = temp->next;
    }
    if(temp == Q->rear)
        count++;

    return count;
}

/* Returns Frnt Element of the Queue */
int frontElement(struct Queue *Q) {
    return Q->front->data;
}

/* Returns the Rear Element of the Queue */
int rearElement(struct Queue *Q) {
    return Q->rear->data;
}

/*
Check's if Queue is empty or not
*/
void isEmpty(struct Queue *Q) {
    if (Q->front == NULL && Q->rear == NULL)
        printf("Empty Queue\n");
    else
        printf("Queue is not Empty\n");
}
/*
Adding elements in Queue
*/
void enqueue(struct Queue *Q, int num) {
    struct ListNode *temp;
    temp = (struct ListNode *)malloc(sizeof(struct ListNode));
    temp->data = num;
    temp->next = NULL;

    if (Q->rear == NULL) {
        Q->front = Q->rear = temp;
    } else {
        Q->rear->next = temp;
        Q->rear = temp;
    }
}

/*
Removes an element from front of the queue
*/
void dequeue(struct Queue *Q) {
    struct ListNode *temp;
    if (Q->front == NULL) {
        printf("\nQueue is Empty \n");
        return;
    } else {
        temp = Q->front;
        Q->front = Q->front->next;
        if(Q->front == NULL){
            Q->rear = NULL;
        }
        printf("Removed Element : %d\n", temp->data);
        free(temp);
    }
}

/*
 Print's Queue
*/
void printQueue(struct Queue *Q) {
    struct ListNode *temp = Q->front;

    if ((Q->front == NULL) && (Q->rear == NULL)) {
        printf("Queue is Empty\n");
        return;
    }

    while (temp != NULL) {
        printf("%d", temp->data);
        temp = temp->next;
        if(temp != NULL)
            printf("-->");
    }
}

void deleteQueue(struct Queue *Q) {
     struct ListNode *temp;
     while(Q->front) {
          temp = Q->front;
          printf("Element being deleted: %d\n", temp->data);
          Q->front = Q->front->next;
          free(temp);
     }
     free(Q);
}


int main() {
    /* Initializing Queue */
    struct Queue *Q;
    Q = CreateQueue();
    /* Adding elements in Queue */
    enqueue(Q, 1);
    enqueue(Q, 3);
    enqueue(Q, 7);
    enqueue(Q, 5);
    enqueue(Q, 10);
    /* Printing Queue */
    printQueue(Q);
    /* Printing size of Queue */
    printf("\nSize of Queue : %d\n", size(Q));
    /* Printing front and rear element of Queue */
    printf("Front Element : %d\n", frontElement(Q));
    printf("Rear Element : %d\n", rearElement(Q));
    /* Removing Element from Queue */
    dequeue(Q);
    dequeue(Q);
    dequeue(Q);
    dequeue(Q);
    dequeue(Q);
    dequeue(Q);
    enqueue(Q, 15);
    enqueue(Q, 100);
    /* Printing Queue */
    printQueue(Q);
    /* Printing size of Queue */
    printf("\nSize of Queue : %d\n", size(Q));
    /* Printing front and rear element of Queue */
    printf("Front Element : %d\n", frontElement(Q));
    printf("Rear Element : %d\n", rearElement(Q));
    /* Removing Queue */
    deleteQueue(Q);
    return 0;
}
