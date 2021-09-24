#include<stdio.h>
#include<stdlib.h>
struct stack
{
int data;
struct stack *next;
};
typedef struct stack NODE;
NODE *top,*temp,*LLnode,*nnode;
NODE *push(NODE *);
NODE *pop(NODE*);
void display(NODE*);
NODE *get_node();
main()
{
int ch;
top=NULL;
do
{
   printf("1--push\n");
   printf("2--pop\n");
   printf("3--display\n");
   printf("4--exit\n");
   printf("enter the choice\n");
   scanf("%d",&ch);
   switch(ch)
   {
   case 1:  top=push(top);
                       break;
    case 2: if(top==NULL)
                    printf("stack is empty\n");
                    else
                    {
                       top=pop(top);
                    }
                    break;
    case 3: display(top);break;
    case 4: exit(0);break;
    default: printf("Invalid choice\n");break;
   }
}while(ch!=4);
}

NODE *get_node()
{
   nnode=(NODE*)malloc(sizeof(NODE));
    if(nnode==NULL)
    {
     printf("memory not allocated\n");
     exit(0);
    }
    else
    {
      printf("enter the element\n");
      scanf("%d",&nnode->data);
    }
     return(nnode);

}

NODE *push(NODE *top)
{
    LLnode=get_node();
    if(top==NULL)
    {
   top=LLnode;
    LLnode->next=NULL;
    }
    else
    {
    LLnode->next=top;
    top=LLnode;
    }
    return(top);


}

NODE *pop(NODE *top)
{
    printf("the element poped=%d\n",top->data);
    if(top->next==NULL)
    {
      free(top);
      top=NULL;
    }
    else
    {
       temp=top;
       top=top->next;
       free(temp);
    }
    return(top);
}

void display(NODE *top)
{
    if(top==NULL)
    printf("stack is empty\n");
    else
    {
       temp=top;
       printf("stack elements are\n");
       while(temp!=NULL)
       {
          printf("%d\n",temp->data);
          temp=temp->next;
       }
    }
}
