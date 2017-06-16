/*
Problem Statement-
Given a Cirular Linked List split it into two halves circular lists. If there are odd number of nodes in the given circular linked list 
then out of the resulting two halved lists, first list should have one node more than the second list. The resultant lists should also be 
circular lists and not linear lists.
*/

/* The structure of linked list is the following
struct Node
{
   int data;
   Node* next;
};   */

//  function which splits the circular linked list.  head is pointer
// to head Node of given lined list.  head1_ref1 and *head_ref2
// are pointers to head pointers of resultant two halves.

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    struct Node *t1=head,*t2=head;
    while(t2->next->next!=head && t2->next!=head){
        t1=t1->next;
        t2=t2->next->next;
    }
    if(t2->next==head){
        t2->next=t1->next;
        t1->next=head;
        *head1_ref=head;
        *head2_ref=t2->next;
    }
    else{
        t2->next->next=t1->next;
        t1->next=head;
        *head1_ref=head;
        *head2_ref=t2->next->next;
    }
}
