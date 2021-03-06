/*
Problem Statement-
Given a linked list, rearrange it such that converted list should be of the form a < b > c < d > e < f .. 
where a, b, c.. are consecutive data node of linked list.
*/
//Time Complexity=O(n)


// This function distributes the Node in zigzag fashion
void zigZagList(Node *head)
{
    // If flag is true, then next node should be greater
    // in the desired output.
    bool flag = true;
 
    // Traverse linked list starting from head.
    Node* current = head;
    while (current->next != NULL)
    {
        if (flag)  /* "<" relation expected */
        {
            /* If we have a situation like A > B > C
               where A, B and C are consecutive Nodes
               in list we get A > B < C by swapping B
               and C */
            if (current->data > current->next->data)
                swap(current->data, current->next->data);
        }
        else /* ">" relation expected */
        {
            /* If we have a situation like A < B < C where
               A, B and C  are consecutive Nodes in list we
               get A < C > B by swapping B and C */
            if (current->data < current->next->data)
                swap(current->data, current->next->data);
        }
 
        current = current->next;
        flag = !flag;  /* flip flag for reverse checking */
    }
}
