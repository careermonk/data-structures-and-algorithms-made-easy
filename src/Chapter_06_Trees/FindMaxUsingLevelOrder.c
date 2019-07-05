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

struct BinaryTreeNode {
    int data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
};

struct ListNode {
    struct BinaryTreeNode *data;
    struct ListNode *next;
};


struct Queue {
    struct ListNode *front;
    struct ListNode *rear;
};

/* Create an empty queue */
struct Queue *createQueue() {
    struct Queue *Q;
    Q = malloc(sizeof(struct Queue));
    if(!Q)
         return NULL;

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
struct BinaryTreeNode* frontElement(struct Queue *Q) {
    return Q->front->data;
}

/* Returns the Rear Element of the Queue */
struct BinaryTreeNode* rearElement(struct Queue *Q) {
    return Q->rear->data;
}

/*
Check's if Queue is empty or not
*/
int isEmpty(struct Queue *Q) {
    if (Q->front == NULL && Q->rear == NULL)
        return 1;
    else
        return 0;
}
/*
Adding elements in Queue
*/
void enQueue(struct Queue *Q, struct BinaryTreeNode *node) {
    struct ListNode *temp;
    temp = (struct ListNode *)malloc(sizeof(struct ListNode));
    temp->data = node;
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
struct BinaryTreeNode* deQueue(struct Queue *Q) {
    struct ListNode *temp;
    if (Q->front == NULL) {
        printf("\nQueue is Empty \n");
        return NULL;
    } else {
        temp = Q->front;
        Q->front = Q->front->next;
        if(Q->front == NULL){
            Q->rear = NULL;
        }
        return temp->data;
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
        printf("%d", temp->data->data);
        temp = temp->next;
        if(temp != NULL)
            printf("-->");
    }
}

void deleteQueue(struct Queue *Q) {
     struct ListNode *temp;
     while(Q->front) {
          temp = Q->front;
          printf("Element being deleted: %d\n", temp->data->data);
          Q->front = Q->front->next;
          free(temp);
     }
     free(Q);
}



struct BinaryTreeNode* createNewNode(int data){  // creating new node
    struct BinaryTreeNode* newNode = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return(newNode);
}

int findMaxUsingLevelOrder(struct BinaryTreeNode *root){
      struct BinaryTreeNode *temp;
    	int max = INT_MIN;
    	struct Queue *Q = createQueue();

    	enQueue(Q,root);

    	while(!isEmpty(Q)) {
    	     temp = deQueue(Q);
    	     // largest of the three values
    	     if(max < temp->data)
    	          max =  temp->data;
    	     if(temp->left)
    	          enQueue (Q, temp->left);
    	     if(temp->right)
    	          enQueue (Q, temp->right);
    	}
    	deleteQueue(Q);
    	return max;
}


int main() {
    //**same BinaryTreeNode is builted as shown in example**
    struct BinaryTreeNode *root = createNewNode(2);
    root->left= createNewNode(7);
    root->right= createNewNode(5);
    root->right->right=createNewNode(19);
    root->right->right->left=createNewNode(4);
    root->left->left=createNewNode(2);
    root->left->right=createNewNode(6);
    root->left->right->left=createNewNode(5);
    root->left->right->right=createNewNode(11);

    printf("Maximum in tree is %d", findMaxUsingLevelOrder(root));
    ;
    return 0;
}
