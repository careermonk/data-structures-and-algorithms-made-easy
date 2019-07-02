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
    struct ListNode* newListNode = (struct ListNode*) malloc(sizeof(struct ListNode));
    newListNode->data  = data;
    /* Next pointer of new ListNode will point to head ListNode of linked list  */
    newListNode->next = *head;
    /* make new ListNode as new head of linked list */
    *head = newListNode;
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

struct ListNode * intersectingListNode(struct ListNode * head1, struct ListNode * head2){
    // get count of both the lists
    int m = getLength(head1);
    int n = getLength(head2);

    //to store the merge point
    struct ListNode * mergePoint = NULL;

    // finding the value of d based on the longer list
    int diff = (m > n) ? (m-n) : (n-m);

    //traverse the smaller longer list for 'diff' steps
    if(m > n){
        while(diff--)
            head1 = head1 -> next;
    }
    else{
        while(diff--)
            head2 = head2 -> next;
    }

    // now both lists have equal ListNodes till the end.
    while(head1 && head2){
        if(head1 -> next->data == head2 -> next->data){
            mergePoint = head1 -> next;
            break;
        }

        head1 = head1 -> next;
        head2 = head2 -> next;
    }

    return mergePoint;
}

int main() {
  struct ListNode *intersectingNode;
  initialize();
  /* Creating a linked List*/
  insert(&head1, 3);
  insert(&head1, 8);
  insert(&head1, 12);
  insert(&head1, 0);
  insert(&head1, 35);
  insert(&head1, 6);
  insert(&head1, 10);
  insert(&head1, 350);
  insert(&head1, 16);
  insert(&head1, 19);
  head1 = reverseLinkedList(head1);
  printf("\nLinked List\n");
  printLinkedList(head1);
  insert(&head2, 13);
  insert(&head2, 18);
  insert(&head2, 112);
  insert(&head2, 10);
  insert(&head2, 135);
  insert(&head2, 16);
  insert(&head2, 10);
  insert(&head2, 350);
  insert(&head2, 16);
  insert(&head2, 19);
  head2 = reverseLinkedList(head2);
  printf("\nLinked List\n");
  printLinkedList(head2);
  intersectingNode = intersectingListNode(head1, head2);
  if (intersectingListNode)
    printf("\n Intersecting ListNode is %d", intersectingNode->data);
  else
    printf("\n NULL \n");
  return 0;
}
