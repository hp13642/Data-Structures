/*
Problem Statement-
Check either the given linked list is palindrome correspoing to its value or not
Solution Approach-
1-take two pointer one slow and one fast increasing by one and two node corespondingly
2-when fast reaches at end slow will be at mid point
3-reverse linked list after mid position
4-now take a pointer at start and compare value of each node start and after mid each and every node
5-if all node value found same then given linked list will be palindrome otherwise not
*/

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
        if(head==NULL || head->next==NULL)
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
    bool isPalindrome(ListNode* head) {
        if(head==NULL)
            return true;
        ListNode *slow=head,*fast=head,*start=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverse(slow->next);
        slow=slow->next;
        while(slow!=NULL){
            if(start->val != slow->val)
                return false;
            slow=slow->next;
            start=start->next;
        }
        return true;
    }
};
