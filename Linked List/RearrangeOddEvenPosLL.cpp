/*
Problem Statement-
Rearrange a linked list in such a way that all odd position nodes are together and all even positions node are together,

*/

/* Node structure
struct Node
{
    int data;
    struct Node* next;
}; */

// Should rearrange given linked list such that all even
// positioned Nodes are before odd positioned.
// Returns new head of linked List.
Node *rearrangeEvenOdd(Node *head)
{
    //if length if less than 3
    if(head==NULL || head->next==NULL || head->next->next==NULL)
        return head;
    struct Node *curr=head->next->next,*prev=head->next,*odd=head,*temp=head;
    
    while(1){
        prev->next=curr->next;
        prev=prev->next;
        curr->next=odd->next;
        odd->next=curr;
        odd=curr;
        curr=prev;
        if(curr==NULL || curr->next==NULL)
            break;
        else
           curr=curr->next; 
    }
    head=temp;
    return head;
}
