/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
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
    //detecting cycle
    int hasCycle(ListNode *head) {
        if(!head || head->next==NULL)
            return -1;       
        ListNode *slow=head,*fast=head->next;
        while(slow && fast && fast->next){
            if(fast==slow){
                //It finds nodes in detected cycle
                return countNodeInCycle(fast,slow);
            }                
            slow=slow->next;
            fast=fast->next->next;
        }
        return -1;
    }
    //counting nodes in detected cycle
    int countNodeInCycle(ListNode* fast,ListNode* slow){
        int n=1;
        fast=fast->next;
        while(fast!=slow){
            n++;
            fast=fast->next;
        }        
        return n;
    }
    ListNode *startingNodeOfCycle(ListNode* head,int n){
        ListNode *first=head,*second=head;
        int c=0;
        //placing one pointer n distance apart to first node
        while(c++!=n) second=second->next;
        while(1){
            if(first==second)
                return first;
            first=first->next;
            second=second->next;
        }
    }
    ListNode *detectCycle(ListNode *head) {
        int countCycleNode=hasCycle(head);
        if(countCycleNode==-1 || head==NULL || head->next==NULL)
            return NULL;
        else
            return startingNodeOfCycle(head,countCycleNode);
    }
};
