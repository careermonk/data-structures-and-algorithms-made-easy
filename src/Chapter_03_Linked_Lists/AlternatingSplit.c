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

struct ListNode * middleNode(struct ListNode *head){
    /* Input Validation */
    if(head == NULL){
        printf("Error: List is empty!\n");
        return NULL;
    }
    struct ListNode *slow, *fast;
    slow = fast = head;
    /* In every iteration, slow pointer will move one node whereas fast pointer will move two ListNodes.
     When fast pointer reaches last ListNode then slow pointer will be pointing to middle ListNode */
    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
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

void alternatingSplit(struct ListNode* head, struct ListNode** head1, struct ListNode** head2) {
    struct ListNode* a = NULL; // Split the nodes to these 'a' and 'b' lists
    struct ListNode* b = NULL;
    struct ListNode* current = head;
    while (current != NULL) {
        // Move a ListNode to 'a'
        struct ListNode* newNode  = current; // the front current node
        current = newNode->next; // Advance the current pointer
        newNode->next = a; // Link the node with the head of list a
        a = newNode;

        // Move a ListNode to 'b'
        if (current != NULL) {
            struct ListNode* newNode = current; // the front source node
            current = newNode->next; // Advance the source pointer
            newNode->next = b; // Link the node with the head of list b
            b = newNode;
        }
    }
    *head1 = a;
    *head2 = b;
}

int main() {
    struct ListNode *head1, *head2;
    initialize();
    /* Creating a linked List*/
    insert(3);
    insert(8);
    insert(12);
    insert(0);
    insert(35);
    insert(6);
    insert(10);
    insert(350);
    insert(16);
    insert(19);
    printf("\nLinked List\n");
    printLinkedList(head);
    alternatingSplit(head, &head1, &head2);
    printf("\nLinked List1\n");
    printLinkedList(head1);
    printf("\nLinked List2\n");
    printLinkedList(head2);
    return 0;
}
