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
} *head1, *head2;

void initialize(){
    head1 = NULL;
    head2 = NULL;
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

// Insert new Node in the beginning of the linked list
void push(struct ListNode** head, int data){
	struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
	newNode->data = data;
	newNode->next = *head;
	*head = newNode;
}

// Solution to give common elements in the reverse
struct ListNode  * intersection1(struct ListNode  *list1, struct ListNode  *list2) {
    struct ListNode  *head = NULL;
    while (list1 != NULL && list2 != NULL) {
        if (list1->data == list2->data) {
            push(&head, list1->data); // Copy common element.
            list1 = list1->next;
            list2 = list2->next;
        } else if (list1->data > list2->data) {
            list2 = list2->next;
        } else { // list1->data < list2->data
            list1 = list1->next;
        }
    }
    return head;
}

// Solution to give common elements in the reverse
struct ListNode  * intersection2(struct ListNode  *list1, struct ListNode  *list2) {
    struct ListNode  *head = NULL;
    struct ListNode* tail;
    while (list1 != NULL && list2 != NULL) {
        if (list1->data == list2->data) {
            if (head == NULL) {
              push(&head, list1->data);
              tail = head;
            }
            else{
              push(&tail->next, list1->data);
              tail = tail->next;
            }
            list1 = list1->next;
            list2 = list2->next;
        } else if (list1->data > list2->data) {
            list2 = list2->next;
        } else { // list1->data < list2->data
            list1 = list1->next;
        }
    }
    return head;
}

// Solution uses the temporary dummy node to build up the result list
struct ListNode  * intersection3(struct ListNode  *list1, struct ListNode  *list2) {
    struct ListNode  dummy;
    struct ListNode  *tail = &dummy;
    dummy.next = NULL;
    while (list1 != NULL && list2 != NULL) {
        if (list1->data == list2->data) {
            push((&tail->next), list1->data); // Copy common element.
            list1 = list1->next;
            list2 = list2->next;
            tail = tail->next;
        } else if (list1->data > list2->data) {
            list2 = list2->next;
        } else { // list1->data < list2->data
            list1 = list1->next;
        }
    }
    return dummy.next;
}

int main() {
  struct ListNode *commonNodes;
  initialize();
  /* Creating a linked List*/
  insert(&head1, 3);
  insert(&head1, 8);
  insert(&head1, 12);
  insert(&head1, 20);
  insert(&head1, 35);
  insert(&head1, 36);
  insert(&head1, 100);
  insert(&head1, 350);
  insert(&head1, 516);
  insert(&head1, 519);
  head1 = reverseLinkedList(head1);
  printf("\nLinked List\n");
  printLinkedList(head1);
  insert(&head2, 3);
  insert(&head2, 8);
  insert(&head2, 13);
  insert(&head2, 22);
  insert(&head2, 35);
  insert(&head2, 36);
  insert(&head2, 200);
  insert(&head2, 380);
  insert(&head2, 516);
  insert(&head2, 529);
  head2 = reverseLinkedList(head2);
  printf("\nLinked List\n");
  printLinkedList(head2);
  commonNodes =  intersection1(head1, head2);
  printf("\nCommon elements\n");
  while (commonNodes != NULL) {
      printf(" %d-->", commonNodes->data);
      commonNodes  = commonNodes->next;
  }
  commonNodes =  intersection2(head1, head2);
  printf("\nCommon elements\n");
  while (commonNodes != NULL) {
      printf(" %d-->", commonNodes->data);
      commonNodes  = commonNodes->next;
  }
  commonNodes =  intersection3(head1, head2);
  printf("\nCommon elements\n");
  while (commonNodes != NULL) {
      printf(" %d-->", commonNodes->data);
      commonNodes  = commonNodes->next;
  }
}
