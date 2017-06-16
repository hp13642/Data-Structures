//Inserting a node with value x in  sorted circular linked list

/* structure for a node */
/*
struct Node
{
  int data;
  Node *next;
};
 */
 
 struct Node* createNode(int data){
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=data;
    t->next=NULL;
    return t;
}
 
void sortedInsert(Node** head_ref, int x)
{
    struct Node *t=*head_ref,*prev,*curr,*t1;
    t1=createNode(x);
    //if linked list is null
    if(!(*head_ref)){
        t1->next=t1;
        *head_ref=t1;
        return;
    }
    // if insertion should done before head
    else if(x<t->data){
        curr=*head_ref;
        while(curr->next!=t){
            curr=curr->next;
        }
        t1->next=t;
        curr->next=t1;
        *head_ref=t1;
        return;
    }
    //else inserting somewhere else
    prev=*head_ref;
    curr=(*head_ref)->next;
    while(curr->data<x && curr!=t){
        prev=curr;
        curr=curr->next;
    }
    t1->next=prev->next;
    prev->next=t1;
    
}
