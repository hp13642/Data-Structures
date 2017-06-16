//Given reference to head of doubly linked list reversing the doubly linked list

/* a Node of the doubly linked list */
/*struct Node
{
  int data;
  Node *next;
  Node *prev;    
};*/
void reverse(Node **head_ref)
{
    struct Node *t=*head_ref,*s=*head_ref;
    if(t==NULL || t->next==NULL)
        return;
    int i=1,j=1;
    while(t->next!=NULL){
        j++;
        t=t->next;
    }
    while(i<j){
        int temp=t->data;
        t->data=s->data;
        s->data=temp;
        i++;
        j--;
        s=s->next;
        t=t->prev;
    }
    
    return;
}
