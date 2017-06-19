/* Linked List Node structure
   struct Node  {
     int data;
     Node *next;
  }
*/

// Should reverse list and return new head.
Node* reverse(Node *head)
{
    if(head->next==NULL)
        return head;
    struct Node *c=head,*n=head->next,*t;
    c->next=NULL;
    while(n!=NULL){
        t=n->next;
        n->next=c;
        c=n;
        n=t;
    }
    head=c;
    return head;
}
