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
} *front, *rear;

/* Create an empty queue */
void initialize() {
    front = rear = NULL;
}

/* Returns queue size */
int size() {
    struct ListNode *temp = front;
    int count = 0;

    if(front == NULL && rear == NULL)
        return 0;

    while(temp != rear){
        count++;
        temp = temp->next;
    }
    if(temp == rear)
        count++;

    return count;
}

/* Returns Frnt Element of the Queue */
int frontElement() {
    return front->data;
}

/* Returns the Rear Element of the Queue */
int rearElement() {
    return rear->data;
}

/*
Check's if Queue is empty or not
*/
void isEmpty() {
    if (front == NULL && rear == NULL)
        printf("Empty Queue\n");
    else
        printf("Queue is not Empty\n");
}
/*
Adding elements in Queue
*/
void enqueue(int num) {
    struct ListNode *temp;
    temp = (struct ListNode *)malloc(sizeof(struct ListNode));
    temp->data = num;
    temp->next = NULL;

    if (rear == NULL) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
}

/*
Removes an element from front of the queue
*/
void dequeue() {
    struct ListNode *temp;
    if (front == NULL) {
        printf("\nQueue is Empty \n");
        return;
    } else {
        temp = front;
        front = front->next;
        if(front == NULL){
            rear = NULL;
        }
        printf("Removed Element : %d\n", temp->data);
        free(temp);
    }
}

/*
 Print's Queue
*/
void printQueue() {
    struct ListNode *temp = front;

    if ((front == NULL) && (rear == NULL)) {
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

void deleteQueue() {
     struct ListNode *temp;
     while(front) {
          temp = front;
          printf("Element being deleted: %d\n", temp->data);
          front = front->next;
          free(temp);
     }
     free(front);
}


int main() {
    /* Initializing Queue */
    initialize();
    /* Adding elements in Queue */
    enqueue(1);
    enqueue(3);
    enqueue(7);
    enqueue(5);
    enqueue(10);
    /* Printing Queue */
    printQueue();
    /* Printing size of Queue */
    printf("\nSize of Queue : %d\n", size());
    /* Printing front and rear element of Queue */
    printf("Front Element : %d\n", frontElement());
    printf("Rear Element : %d\n", rearElement());
    /* Removing Element from Queue */
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    enqueue(15);
    enqueue(100);
    /* Printing Queue */
    printQueue();
    /* Printing size of Queue */
    printf("\nSize of Queue : %d\n", size());
    /* Printing front and rear element of Queue */
    printf("Front Element : %d\n", frontElement());
    printf("Rear Element : %d\n", rearElement());
    /* Removing Queue */
    deleteQueue();
    return 0;
}
