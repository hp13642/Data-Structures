/*
Problem Statement-
Given a singly linked list, remove all the nodes which have a greater value on right side.
Solution Approach-
1-Delete all such node in single pass if any node got deleted then update the update variable as true 
2- repeat step 1 until update variable got false then it break


Another Best Approach-
Algorithm-
1. Reverse the list.
2. Traverse the reversed list. Keep max till now. If next node < max, then delete the next node, 
    otherwise max = next node. 3. Reverse the list again to retain the original order. Time Complexity: O(n) 
*/

/*

The structure of linked list is the following

struct Node
{
int data;
Node* next;
};

*/
Node *compute(Node *head)
{
    if(!head)
        return head;
    while(1){
        struct Node *t=head,*prev=head,*t2;
    bool h=true,upd=false;
    while(t->next!=NULL){
        if(t->data<t->next->data){
            upd=true;
            t2=t->next;
            if(h)
                head=t2;
            else
                prev->next=t2;
            free(t);
            t=t2;
        }
        else{
            h=false;
            prev=t;
            t=t->next;
        }
    }
    if(!upd)
        break;
    }
    return head;
}
