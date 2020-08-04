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

struct DLLNode {
    int data;
    struct DLLNode *prev;
    struct DLLNode *next;
};

//length of the list
int length(struct DLLNode *head) {
    struct DLLNode *current = head;
    int count = 0;
    if(head == NULL)
        return 0;

    while (current != NULL){
        current = current->next;
        count++;
    }
    return count;
}

// display list using iteration
void printList(struct DLLNode *head) {
    struct DLLNode *current = head;
    if(head == NULL)
        return;
    while (current != NULL){
    	printf ("%d-->", current->data);
        current = current->next;
    }
}


// Insert at the beginning of the list
void insertAtBeginning(struct DLLNode **head, int data){
    struct DLLNode *current = *head;
    struct DLLNode *newNode = (struct DLLNode *) (malloc(sizeof(struct DLLNode)));
    if(!newNode) {
        printf("Memory Error");
        return;
    }
		newNode->prev = NULL;
    newNode->data = data;
    newNode->next = NULL;
    if(current == NULL){
        *head = newNode;
        return;
    }

    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

// insert item at the end of the list
void insertAtEnd(struct DLLNode **head, int data){
	struct DLLNode *current = *head;
	struct DLLNode *newNode = (struct DLLNode *)(malloc(sizeof(struct DLLNode)));
	if(!newNode) {
		printf("Memory Error");
		return;
	}
	newNode->prev = NULL;
	newNode->data = data;
	newNode->next = NULL;
	if(*head ==NULL){
		*head = newNode;
		return;
	}

	while (current->next != NULL)
		current = current->next;

	// current points to tail node
	newNode->prev = current;
	current->next = newNode;
}

void insert(struct DLLNode **head, int data, int position) {
    int k = 1;
    struct DLLNode *temp, *newNode;
    newNode = (struct DLLNode *) malloc(sizeof ( struct DLLNode ));
    if(!newNode) { 				//Always check for memory errors
        printf ("Memory Error");
        return;
    }
    newNode->prev = NULL;
  	newNode->data = data;
  	newNode->next = NULL;

    if(position == 1) {			//Inserting a node at the beginning
        newNode->next = *head;
        newNode->prev = NULL;

        if(*head)
           (*head)->prev = newNode;

        *head = newNode;
        return;
    }
    temp = *head;
    while (k < position-1 && temp->next != NULL) {
        temp = temp->next;
        k++;
    }

    if(k < position-1){
        printf("Desired position does not exist\n");
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if(temp->next)
        temp->next->prev = newNode;

    temp->next = newNode;
    return;
}


void deleteLastNode(struct DLLNode **head) {
    struct DLLNode *temp = *head, *current = *head;

    if(*head == NULL) {
        printf( "List empty!");
        return;
    }
    while (current->next != NULL){
        current = current->next;
    }
    temp = current->prev;
    temp->next = current->next;
    free(current);
    return;
}

void deleteFrontNode (struct DLLNode **head) {
    struct DLLNode *temp = *head;

    if(*head == NULL) {
        printf("List empty");
        return;
    }
    temp = *head;
    *head = (*head)->next;
    (*head)->prev = NULL;
    free(temp);
    return;
}

void delete(struct DLLNode **head, int position) {
    struct DLLNode *temp2, *temp = *head;
    int k = 1;
    if(*head ==  NULL) {
        printf("List is empty"); 
        return;
    }
    if(position == 1) {
        *head = (*head)->next;

    if(*head != NULL)
         (*head)->prev = NULL;
        free(temp);
        return;
    }
    while(k < position && temp->next!=NULL) {
        temp = temp->next;
        k++;
    }
    if(k < position){
        printf("Desired position does not exist\n");
        return;
    }

    temp2 = temp->prev;
    temp2->next = temp->next;

    if(temp->next) // Deletion from Intermediate Node
        temp->next->prev = temp2;

    free(temp);
    return;
}


int main(){
    struct DLLNode *head = NULL;
    printf("%d \n",length(head));
    insertAtBeginning(&head, 30);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 10);
    printf("List length is %d \n",length(head));
    printList(head);
    printf("\n");
  	insertAtEnd(&head, 40);
  	insertAtEnd(&head, 50);
  	insertAtEnd(&head, 60);
  	printf("List length is %d \n",length(head));
  	printList(head);
  	printf("\n");
    insert(&head, 15, 2);
    insert(&head, 35, 4);
    insert(&head, 55, 6);
    insert(&head, 115, 12);
    printf("List length is %d \n",length(head));
    printList(head);
    printf("\n");
    deleteFrontNode(&head);
    printf("List length is %d \n",length(head));
    printList(head);
    printf("\n");
    deleteLastNode(&head);
    printf("List length is %d \n",length(head));
    printList(head);
    printf("\n");
    delete(&head, 7);
    printf("List length is %d \n",length(head));
    printList(head);
    printf("\n");
    delete(&head, 2);
    printf("List length is %d \n",length(head));
    printList(head);
    printf("\n");
    delete(&head, 6);
    printf("List length is %d \n",length(head));
    printList(head);
    printf("\n");
    return 0;
}
