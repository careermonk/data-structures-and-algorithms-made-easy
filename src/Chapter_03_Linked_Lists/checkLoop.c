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


int checkLoop(struct ListNode *head) {
    struct ListNode *slow, *fast;
    slow = fast = head;
   
    while(fast && fast->next) {
        /* Slow pointer will move one node per iteration whereas fast node will move two nodes per iteration */
        slow = slow->next;
        fast  = fast->next->next;
        if (slow == fast) {
           printf("\n Linked list contains a loop\n");
           return 1;
        }
    }
    printf("\n No loop in linked list\n");
    return 0;
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
    struct ListNode *middle;
    initialize();
    /* Creating a linked List*/
    insert(8);  
    insert(3); 
    insert(2); 
    insert(7);
    insert(9);

    printf("\nLinked List\n");
    printLinkedList(head);
    checkLoop(head);
    /* Create loop in linked list. Set next pointer of last node to second node from head */
    head->next->next->next->next->next = head->next;
    checkLoop(head);
    return 0;
}
