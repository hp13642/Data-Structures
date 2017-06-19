/*
Problem Statement-
Given two linked lists, represented as linked lists (every character is a node in linked list). 
Write a function compare() that works similar to strcmp(), i.e., it returns 0 if both strings are same, 
1 if first linked list is lexicographically greater, and -1 if second string is lexicographically greater.

*/

/* Linked list Node structure
struct Node
{
    char c;
    Node *next;
}; */

// Compare two strings represented as linked lists
int compare(Node *list1, Node *list2) 
{
    struct Node *t1=list1,*t2=list2;
    while(t1!=NULL && t2!=NULL){
        if(!t1)
            return -1;
        if(!t2)
            return 1;
        if(t1->c > t2->c)
            return 1;
        else if(t1->c < t2->c)
            return -1;
        else{
            t1=t1->next;
            t2=t2->next;
        }
    }
    if(!t2 && !t2)
        return 0;
    if(!t1)
        return -1;
    if(!t2)
        return 1;
}
