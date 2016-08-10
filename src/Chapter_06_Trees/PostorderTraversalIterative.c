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
#define MAXSIZE 10

struct SimpleArrayStack {
    int top;
    int capacity;
    unsigned int *addresses;    //storing node addresses in array
};
struct BinaryTreeNode{
    int data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
};
struct SimpleArrayStack *CreateStack(){
    struct SimpleArrayStack *S = malloc(sizeof(struct SimpleArrayStack));  
    if(!S) 
        return NULL;
    S->capacity = MAXSIZE;
    S->top = -1;
    S->addresses = malloc(S->capacity * sizeof(unsigned int));	

    if(!S->addresses) 
        return NULL;
    return S;
}

int IsFullStack(struct SimpleArrayStack *S){
    return (S->top == S->capacity-1);
}

void Push(struct SimpleArrayStack *S, struct BinaryTreeNode *data){
    // No overflow in this implementation
    if(IsFullStack(S))   {
        printf("Overflow: Stack full");
        return;
    }
    ++S->top;
    S->addresses[S->top] = data;
}

int IsEmptyStack(struct SimpleArrayStack *S){
    return S->top == -1;
}

struct BinaryTreeNode *Top(struct SimpleArrayStack *S){
    if(IsEmptyStack(S))     
     return NULL;

    return S->addresses[S->top];
}

struct BinaryTreeNode *Pop(struct SimpleArrayStack *S){
    if(IsEmptyStack(S)){  
        printf("Underflow: Stack empty");
        return NULL;
    }
    return S->addresses[S->top--];
}

void DeleteStack(struct SimpleArrayStack *S){
    if(S) {
        if(S->addresses) 
            free(S->addresses);
        free(S);
    }
}

void postOrderIterative(struct BinaryTreeNode* root){
    struct SimpleArrayStack *S = CreateStack();
    struct BinaryTreeNode *previous = NULL;
    do{ 
        while (root!=NULL){ 
            Push(S, root);
            root = root->left;
        }
        while(root == NULL && !IsEmptyStack(S)){
            root = Top(S);
            if(root->right == NULL || root->right == previous){
                printf("%d ", root->data);
                Pop(S);
                previous = root;
                root = NULL;
            }
            else
                root = root->right;
        }
    }while(!IsEmptyStack(S));
} 

int testPostOrderIterative(){
    /* Sample binary tree is
            9
          /   \
        19      1
         \    /  \
          3  6   10
    */
    struct BinaryTreeNode* root = createNewNode(9);
    root->left = createNewNode(19);
    root->right = createNewNode(1);
    struct BinaryTreeNode* temp = root->left;
    temp->right = createNewNode(3);
    temp = root->right;
    temp->left = createNewNode(6);
    temp->right = createNewNode(10);
    postOrderIterative(root);
    return 0;
}