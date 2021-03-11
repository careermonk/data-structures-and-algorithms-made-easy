/*Copyright (c) 2016 CareerMonk Publications and others.
#E-Mail            : info@careermonk.com 
#Creation Date     : 2008-01-10 06:15:46 
#Created by        : Narasimha Karumanchi 
#Book Title        : Data Structures And Algorithms Made Easy
#Warranty          : This software is provided "as is" without any 
#                    warranty; without even the implied warranty of 
#                    merchantability or fitness for a particular purpose.*/

#include<stdio.h>
#include <stdlib.h>
#include <limits.h>

struct ListNode{
    int data;
    struct ListNode *next;
};

struct Stack{
    struct ListNode *top;
};

struct Stack *createStack(){
    struct Stack *stk;
    stk = malloc(sizeof(struct Stack));
    stk->top = NULL;
    return stk;
}

void push(struct Stack *stk, int data){
    struct ListNode *temp;
    temp = malloc(sizeof(struct ListNode));
    if(!temp){
        printf("\nStack/Heap overflow");
        return;
    }
    temp->data = data;
    temp->next = stk->top;
    stk->top = temp;
}

int size(struct Stack *stk){
    // we can improve the size function by adding extra size variable in stack structure
    // and update it while push/pop operations
    int count = 0;
    struct ListNode *temp;
    if(isEmpty(stk))  
        return 0;
    temp = stk->top;
    while (temp){
        count++;
        temp = temp->next;
    }
    return count;
}

int isEmpty(struct Stack *stk){
    return stk->top == NULL;
}

int pop(struct Stack *stk){
    int data;
    struct ListNode *temp;
    if(isEmpty(stk))   
        return INT_MIN;
    temp = stk->top;
    stk->top = stk->top->next;
    data = temp->data;
    free(temp);
    return data;
}

int peek(struct Stack * stk){
    if(isEmpty(stk))  
        return INT_MIN;
    return stk->top->data;
}

void deleteStack(struct Stack *stk){
    struct ListNode *temp, *p;
    p = stk->top;
    while( p) {
        temp = p->next;
        free(p);
        p = temp;
    }
    free(stk);
 }
 int main(){
    int i = 0;
    struct Stack *stk = createStack();

    for(i = 0; i <= 10; i++){
        push(stk, i);
    }

    printf("Top element is %d\n", peek(stk));
    printf("Stack size is %d\n", size(stk));

    for (i = 0; i <= 10; i++){
        printf("Popped element is %d\n", pop(stk));
    }

    if (isEmpty(stk))
        printf("Stack is empty");
    else
        printf("Stack is not empty");

    deleteStack(stk);
    return 0;
 }
