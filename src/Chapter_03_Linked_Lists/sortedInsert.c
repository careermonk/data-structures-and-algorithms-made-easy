/*Copyright (c) 2008 CareerMonk Publications and others.
#E-Mail            : info@careermonk.com 
#Creation Date     : 2008-01-10 06:15:46 
#Created by        : Narasimha Karumanchi 
#Book Title        : Data Structures And Algorithms Made Easy
#Warranty          : This software is provided "as is" without any 
#                    warranty; without even the implied warranty of 
#                    merchantability or fitness for a particular purpose.*/
#include <stdio.h>
#include <stdlib.h>
  
/* A structure of linked list ListNode */
struct ListNode {
  int data;
  struct ListNode *next;
} *head;
 
void initialize(){
    head = NULL;
}
 
/* 
Given a Inserts a ListNode in pTemp of a singly linked list. 
*/
void insert(int data) {
    /* Create a new Linked List ListNode */
    struct ListNode* newNode = (struct ListNode*) malloc(sizeof(struct ListNode));
    newNode->data  = data;
    /* Next pointer of new ListNode will point to head ListNode of linked list  */
    newNode->next = head;
    /* make new ListNode as new head of linked list */
    head = newNode;
    printf("Inserted Element : %d\n", data);
}
 
int getLength(struct ListNode *head){
    /* Input Validation */
    if (head == NULL) { 
       printf("Error : Invalid ListNode pointer !!!\n");       
       return 0;  
    }
      
    int length =0;
    while(head != NULL){
        head = head->next;
        length++;
    }
    return length;
}

// Function to insert the given node into the correct sorted position in the given list sorted in increasing order
void sortedInsert(struct ListNode** head, int data){
    /* Create a new Linked List ListNode */
    struct ListNode* newNode = (struct ListNode*) malloc(sizeof(struct ListNode));
    newNode->data  = data;
    // Special case for the head end
    if (*head == NULL || (*head)->data >= newNode->data){
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // Locate the node before the point of insertion
    struct ListNode* current = *head;
    while(current->next != NULL && current->next->data < newNode->data)
        current = current->next;

    newNode->next = current->next;
    current->next = newNode;
}

/*
Prints a linked list from head ListNode till tail ListNode 
*/
void printLinkedList(struct ListNode *ListNodePtr) {
  while (ListNodePtr != NULL) {
     printf("%d", ListNodePtr->data);
     ListNodePtr = ListNodePtr->next;
     if(ListNodePtr != NULL)
         printf("-->");
  }
}
  
int main() {
    struct ListNode *temp;
    initialize();
    /* Creating a linked List*/
    sortedInsert(&head, 1);  

    sortedInsert(&head, 19);
    sortedInsert(&head, 5); 
    sortedInsert(&head, 61); 
    sortedInsert(&head, 7);

    printf("\nLinked List\n");
    printLinkedList(head);
    return 0;
}
