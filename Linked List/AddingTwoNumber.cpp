/*
Problem Statement-
Adding two number given in a singly linked list in reverse order that is lsb to msb
as number 45 is represented as 5->4->null in linked list
Soltution approach-
1-create new linked list of result
2-handle case of carry at end when on linked list is ended 
3- also think about case of 9 at end of linked list
*/

/*struct Node
{
    int data;
   Node* next;
}; */
//write a function returns the resultant linked list
struct Node* createNode(int data){
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=data;
    t->next=NULL;
    return t;
}
Node*  addTwoLists(Node* first, Node* second){
    struct Node* res = NULL; // res is head node of the resultant list
    struct Node *temp, *prev = NULL;
    int carry = 0, sum;
 
    while (first != NULL || second != NULL) //while both lists exist
    {
        // Calculate value of next digit in resultant list.
        // The next digit is sum of following things
        // (i)  Carry
        // (ii) Next digit of first list (if there is a next digit)
        // (ii) Next digit of second list (if there is a next digit)
        sum = carry + (first? first->data: 0) + (second? second->data: 0);
 
        // update carry for next calulation
        carry = (sum >= 10)? 1 : 0;
 
        // update sum if it is greater than 10
        sum = sum % 10;
 
        // Create a new node with sum as data
        temp = createNode(sum);
 
        // if this is the first node then set it as head of the resultant list
        if(res == NULL)
            res = temp;
        else // If this is not the first node then connect it to the rest.
            prev->next = temp;
 
        // Set prev for next insertion
        prev  = temp;
 
        // Move first and second pointers to next nodes
        if (first) first = first->next;
        if (second) second = second->next;
    }
 
    if (carry > 0)
      temp->next = createNode(carry);
    return res;
}
