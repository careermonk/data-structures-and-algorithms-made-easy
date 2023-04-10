#include <iostream>
#include<queue>
using namespace std;

//structure of node
struct node{
    int data;
    struct node *left;
    struct node *right;
}*head;

//inserts node with data= value
struct node * insert(struct node * ptr, int value){

    node *temp = new node;
    temp->data = value;
    temp->left = NULL, temp->right = NULL;

    if(ptr == NULL)
       ptr= temp;

    else{

        if(value < ptr->data)
            ptr->left = insert(ptr->left, value);

        else if(value > ptr->data)
            ptr->right = insert(ptr->right, value);

        else
            cout<<endl<<" Duplicate key not allowed!";
    }
    return ptr;
}

// deleting a node with value = key
struct node* deletenode(struct node* ptr, int key )
{
   node* successor , *tmp =new node;
      if(ptr == NULL)
           cout<<endl<<" Nothing to delete"<<endl;

      else if (key < ptr->data )
         ptr->left = deletenode( ptr->left , key );

      else if ( key > ptr->data )
        ptr -> right = deletenode( ptr -> right, key);

      else
      {
         // Case C -> Two Child
         if (ptr->left != NULL && ptr->right != NULL)
         {
            successor = ptr->right;
            while (successor->left)
            {
               successor = successor->left ;
            }
            ptr->data = successor->data ;
            ptr->right = deletenode(ptr->right , successor->data ) ;
         }
         else
         {
            tmp = ptr ;
            // Case B -> One Child
            if (ptr->left != NULL )
               ptr = ptr -> left;

            else if (ptr->right != NULL)
               ptr = ptr->right ;

            //  Case A -> No Child
            else
               ptr = NULL ;
            delete tmp;
         }
    }
      return ptr;
}

//display function
void display( struct node *ptr, int level)
{
    int i;
    if (ptr != NULL)
    {
        display(ptr->right, level+1);
        cout<<endl;
        if (ptr == head)
            cout<<"Root->:  ";
        else
        {
            for (i = 0;i < level;i++)
                cout<<"      ";
        }
        cout<<ptr->data;
        display(ptr->left, level+1);
    }

}

//finds height of tree recursively
int height(struct node * head){

    if(head == NULL)
        return 0;
    return max(height(head->left), height(head->right))+1;

}

//counts number of nodes in BST recursively
int count(struct node * head){

    if(head == NULL)
        return 0;
    return count(head->left) + count(head->right) + 1;
}

//returns number of internal nodes(non-leaf nodes) in BST using recursion
int internalnode(struct node * head){

    if(head == NULL)
        return 0;

    if(head-> left == NULL || head-> right == NULL)
        return 0;

    return internalnode(head->left)+ internalnode(head->right) + 1;
}

//returns number of external nodes(leaf nodes) in BST using recursion
int externalnode(struct node * head){

    if(head == NULL)
        return 0;

    if(head-> left == NULL && head-> right == NULL)
        return 1;

    return externalnode(head->left)+ externalnode(head->right);
}

//returns number of internal nodes iteratively
void qinternal(){

    if(head ==  NULL)
        return;

    queue <node*> q;
    int count=0;
    q.push(head);

    while(!q.empty()){

        node *temp = q.front();
        q.pop();

        if(temp->left && temp-> right)
            count++;

        else{

            if(temp->left)
                q.push(temp->left);

            if(temp->right)
                q.push(temp->right);
        }
    }
    cout<<endl<<" number of full nodes = "<< count<<endl;
}

//mirror image of the BST using recursion
void mirror(struct node *ptr){

    if(ptr == NULL)
        return;

    else{
        node *temp = new node;
        mirror(ptr->left);
        mirror(ptr->right);
        temp = ptr->left;
        ptr->left = ptr->right;
        ptr->right = temp;
    }
}

//mirror image of BST using queue
void qmirror(){

    if(head == NULL)
        return;
    queue < node*> q;
    q.push(head);

    while(!q.empty()){

        node * temp = q.front();
        q.pop();

        swap(temp->left, temp->right);

        if(temp->left)
            q.push(temp->left);

        if(temp->right)
            q.push(temp->right);
    }
}

//finds the deepest node of the BST
void deepestnode(){

    if(head == NULL)
        return;

    else{
            node * temp= new node;
        queue <node*> q;
        q.push(head);

        while(!q.empty()){

            temp = q.front();
            q.pop();

            if(temp->left)
                q.push(temp->left);

            if(temp->right)
                q.push(temp->right);
        }
        cout<<endl<< temp-> data<<" is deepest node"<<endl;
    }
}

//searches a given key in BST recursively
int search(struct node* ptr, int key){
    int temp;
    if(ptr == NULL)
        return 0;
    if( key == ptr->data)
        return 1;
    temp = search(ptr->left, key);
    if(temp != 0)
       return temp;
    return search(ptr->right, key);


}

//searches a given key in BST iteratively
void qsearch(int key){

    if(head == NULL){
        cout<<endl<<" Tree empty!"<<endl;
        return;
    }

    queue< node*> q;
    q.push(head);
    while(!q.empty()){
         node * temp= new node;
         temp= q.front();
         q.pop();
         if(temp->data == key){
                cout<<endl<<" data found"<<endl;
                return;
         }
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    cout<<endl<<" not found"<<endl;
}


//the driver function(can be made menu-driven)
int main(){

    head = insert(head,10);
    head = insert(head, 15);
    head = insert(head, 5);
    head = insert(head, 67);
    head = insert(head, 2);
    head = insert(head, 0);
    head = insert(head, 29);
    head = insert(head, 17);

   display(head,1);
    head = deletenode(head,5);
    
    cout<<endl<<"height : "<<height(head);
    cout<<endl<<"Number of nodes : "<<count(head);
    cout<<endl<<"Number of internal nodes : "<<internalnode(head);
    cout<<endl<<"Number of external nodes : "<<externalnode(head);

    mirror(head);
    display(head, 1);
    qmirror();
    display(head, 5);
    deepestnode();
    qinternal();
    cout<<" SEARCHING... "<<endl;
    if(search(head,19))
        cout<<endl<<" data found"<<endl;
    else
        cout<<endl<<" data not found"<<endl;
    qsearch(29);
}
