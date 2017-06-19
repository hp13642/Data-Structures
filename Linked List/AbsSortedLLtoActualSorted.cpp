/*
Problem statement-
Given a linked list which is sorted based on absolute values. Sort the list based on actual values.
Solution Approach-
1-Reverse linked list
2-Now all positive value present left side will be right most side
3-take one pointer (t) at the end
4-travers reversed linked list from start  to 't'if any positive value found add it next to end
5- when next positive value came it will be definetly less than previous positive value so add it after choosen pointer at end 't'
*/
/* The structure of the Linked list Node is as follows:
struct Node
{
    Node* next;
    int data;
}; */

/*Your method shouldn't print anything
 it should transform the passed linked list */
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
void sortList(Node** head)
{
    struct Node *s,*t,*t1=*head,*t2,*prev=NULL;
    t1=reverse(t1);
    s=t1;
    while(s->next!=NULL)
        s=s->next;
    t=s;
    t2=t1;
    *head=t1;
    while(t2!=s){
        if(t2->data>0){
            if(t1==t2){
                t1=t1->next;
                t2->next=t->next;
                t->next=t2;
                //t=t2;
                t2=t1;
            }
            else{
                prev->next=t2->next;
                t2->next=t->next;
                t->next=t2;
                //t=t2;
                t2=prev->next;
            }    
        }
        else{
            prev=t2;
            t2=t2->next;
        }
    }
    *head=t1;
}
