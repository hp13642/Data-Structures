//Detecting a cycle in a given singly linked list

bool hasCycle(ListNode *head) {
        if(!head || head->next==NULL)
            return false;       
        ListNode *slow=head,*fast=head->next;
        while(slow && fast && fast->next){
            if(fast==slow)
                return true;
            slow=slow->next;
            fast=fast->next->next;
        }
        return false;
    }
