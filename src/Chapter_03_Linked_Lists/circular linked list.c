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

struct CLLNode{
	int data;
	struct CLLNode* next;
};

struct CLLNode *head = NULL;

//length of the list
int length(struct CLLNode *head) {
    struct CLLNode *current = head;
    int count = 0;
    if(head == NULL) 
        return 0;

    do {      
        current = current->next;
        count++;
    } while (current != head);

    return count;
}

// display list using iteration
void printList(struct CLLNode *head) {
    struct CLLNode *current = head;
    if(head == NULL) 
        return;

    do {      
        printf ("%d-->", current->data);
        current = current->next;
    } while(current != head);
}

// Insert at the beginning of the list 
void insertAtBeginInCLL (struct CLLNode **head, int data){
    struct CLLNode *current = *head;
    struct CLLNode *newNode = (struct CLLNode *) (malloc(sizeof(struct CLLNode)));
    if(!newNode) { 
        printf("Memory Error"); 
        return;
    }
    newNode->data = data;
    newNode->next = newNode;
    if(current == NULL){
        *head = newNode;
        return;
    }
    
    while (current->next != *head) 
        current = current->next;
        
    newNode->next = *head;
    current->next = newNode;
    *head = newNode;
}

// insert item at the end of the list
void insertAtEndInCLL(struct CLLNode **head, int data){
    struct CLLNode *current = *head;
    struct CLLNode *newNode = (struct CLLNode *) (malloc(sizeof(struct CLLNode)));
    if(!newNode) {
        printf("Memory Error"); 
        return;
    }
    newNode->data = data;
    while (current->next != *head) 
        current = current->next;

    newNode->next = newNode;

    if(*head ==NULL)
        *head = newNode;
    else {	
        newNode->next = *head;
        current->next = newNode;
    }
}

void deleteLastNodeFromCLL (struct CLLNode **head) {
    struct CLLNode *temp = *head, *current = *head;

    if(*head == NULL) {
        printf( "List empty!");  
        return;
    }
    while (current->next != *head) {
        temp = current;
        current = current->next;
    }
    temp->next = current->next;
    free(current);
    return;
}
void deleteFrontNodeFromCLL (struct CLLNode **head) {
    struct CLLNode *temp = *head;
    struct CLLNode *current = *head;

    if(*head == NULL) {
        printf("List empty");  
        return;
    }

    while (current->next != *head) 
        current = current->next;

    current->next = (*head)->next;
    *head = (*head)->next;

    free(temp);
    return;
}


int main(){
    struct CLLNode *head = NULL;
    printf("%d \n",length(head));
    insertAtBeginInCLL(&head, 30);
    insertAtBeginInCLL(&head, 20);
    insertAtBeginInCLL(&head, 10);
    printf("List length is %d \n",length(head));
    printList(head);
    printf("\n");
    insertAtEndInCLL(&head, 40);
    insertAtEndInCLL(&head, 50);
    insertAtEndInCLL(&head, 60);
    printf("List length is %d \n",length(head));
    printList(head);
    deleteLastNodeFromCLL(&head);
    printf("List length is %d \n",length(head));
    printList(head);
    deleteFrontNodeFromCLL(&head);
    printf("List length is %d \n",length(head));
    printList(head);
    return 0;
}
