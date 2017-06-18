//Swapping node in singly linked list pairwise

/*
  Pairwise swap a linked list
  The input list will have at least one element  
  node is defined as 
  struct node
  {
     int data;
     struct node *next;
  }
*/

void pairWiseSwap(struct node *head)
{
    if(head==NULL || head->next==NULL)
        return;
    struct node *t1=head;
    bool h=false;
    while(t1!=NULL && t1->next!=NULL){
        int temp=t1->next->data;
        t1->next->data=t1->data;
        t1->data=temp;
        t1=t1->next->next;
    }
}
