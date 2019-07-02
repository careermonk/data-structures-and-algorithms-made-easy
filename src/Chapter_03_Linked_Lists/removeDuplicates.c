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
void insert(struct ListNode **head, int data) {
    /* Create a new Linked List ListNode */
    struct ListNode* newNode = (struct ListNode*) malloc(sizeof(struct ListNode));
    newNode->data  = data;
    /* Next pointer of new ListNode will point to head ListNode of linked list  */
    newNode->next = *head;
    /* make new ListNode as new head of linked list */
    *head = newNode;
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

// Prints a linked list from head ListNode till tail ListNode
void printLinkedList(struct ListNode *head) {
  while (head != NULL) {
     printf("%d", head->data);
     head = head->next;
     if(head != NULL)
         printf("-->");
  }
}

/* Reverses a given linked list, and return the head pointer of reversed linked list */
struct ListNode* reverseLinkedList(struct ListNode *head) {
    struct ListNode *previous, *current, *next;
    previous = NULL;
    current = head;

    while (current != NULL) {
        next  = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    return previous;
}

// Remove duplicates from a sorted list
void removeDuplicates(struct ListNode **head) {
    struct ListNode* current = *head;
    if (current == NULL) return; // do nothing if the list is empty
    // Compare current ListNode with next ListNode
    while(current->next!=NULL) {
        if (current->data == current->next->data) {
            struct ListNode* nextNext = current->next->next;
            free(current->next);
            current->next = nextNext;
        }
        else {
            current = current->next; // only advance if no deletion
        }
    }
}

int main() {
  struct ListNode *commonNodes;
  initialize();
  /* Creating a linked List*/
  insert(&head, 3);
  insert(&head, 8);
  insert(&head, 13);
  insert(&head, 13);
  insert(&head, 35);
  insert(&head, 120);
  insert(&head, 200);
  insert(&head, 200);
  insert(&head, 516);
  insert(&head, 516);
  printf("\nLinked List\n");
  head = reverseLinkedList(head);
  printLinkedList(head);
  removeDuplicates(&head);
  printf("\nLinked List\n");
  printLinkedList(head);
}
