//Reversing a given singly linked list from m'th node to n'th node

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode *head){
    if(head->next==NULL)
        return head;
    ListNode *c=head,*n=head->next,*t;
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m==n)
            return head;
        int c1=1,c2=1;
        ListNode *t1=head,*t2=head,*t3;
        while(c1<m-1){
            t1=t1->next;
            t2=t2->next;
            c1++;
            c2++;
        }
        while(c2!=n){
            t2=t2->next;
            c2++;
        }
        //Saving node after 'n'
        t3=t2->next;
        //Putting null at the end of target sub linked list 
        t2->next=NULL;
        //reversing from m'th node n'th node
        if(m==1){
            t1=reverse(t1);
            head=t1;
        }
        else
            t1->next=reverse(t1->next);
        while(t1!=NULL){
            cout<<t1->val<<" ";
            t1=t1->next;
        }
        t1=head;
        //going to the end of reversed linked list
        while(t1->next!=NULL)
            t1=t1->next;
        t1->next=t3;
        return head;
    }
};
