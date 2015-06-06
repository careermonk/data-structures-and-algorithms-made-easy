#include<stdio.h>
#include<stdlib.h>
struct listNode{
	int data;
	struct listNode *prev;
	struct listNode *next;
};
int listLength(struct listNode *head){
	int count;
	while(head!=NULL){
		count++;
		head=head->next;
	}
	return count;
}
void insertInLinkedList(struct listNode **head, int data, int pos){
	int k=1;
	struct listNode *p, *q, *newNode;
	newNode=(struct listNode *)malloc(sizeof(struct listNode));
	if(!newNode){
		printf("Memory Error");
		return;
	}
	newNode->data=data;
	if(pos==1 || *head==NULL){
		newNode->next=*head;
		newNode->prev=NULL;
		if(*head){
			(*head)->prev=newNode;
		}
		*head=newNode;
	}
	else{
		p=*head;
		while(p!=NULL && k<pos){
			k++;
			q=p;
			p=p->next;
		}
		newNode->next=p;
		newNode->prev=q;
		q->next=newNode;
		if(p){
			p->prev=newNode;
		}
	}
}
void deleteNodeFromLinkedList(struct listNode **head, int pos){
	int k=1;
	struct listNode *temp, *q, *p;
	if(!head){
		printf("List empty");
		return;
	}
	if(pos==1){
		temp=*head;
		*head=(*head)->next;
		if(*head){
			(*head)->prev=NULL;
		}
		free(temp);
	}
	else{
		p=*head;
		while(p!=NULL && k<pos){
			k++;
			q=p;
			p=p->next;
		}
		if(p==NULL){
			printf("No such position exist");
			return;
		}
		temp=p;
		q->next=p->next;
		if(p->next){
			p->next->prev=q;
		}
		free(temp);
	}
}
void printList(struct listNode *head){
	while(head!=NULL){
		printf("%d ",head->data);
		head=head->next;
	}
	printf("\n");
}
int main(){
	struct listNode *head;
	printf("Elements in list are :%d\n",listLength(head));
	printList(head);
	insertInLinkedList(&head,2,3);
	insertInLinkedList(&head,5,3);
	insertInLinkedList(&head,9,1);
	insertInLinkedList(&head,10,3);
	printf("Elements in list are :%d\n",listLength(head));
	printList(head);
	deleteNodeFromLinkedList(&head,3);
	printList(head);
	return 0;
}
