/*
Structure of the linked list node is as
struct node
{
    int data;
    struct node *next;
};
*/

// function inserts the data in front of the list
void insertAtBegining(struct node** headRef, int newData)
{
    // Code here
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=newData;
    if(*headRef==NULL){
        newnode->next=NULL;
        *headRef=newnode;
       // return;
    }
    else{
        newnode->next=*headRef;
        *headRef=newnode;
    }
}

// function appends the data at the end of the list
void insertAtEnd(struct node** headRef, int newData)
{
    // Code here
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=newData;
    newnode->next=NULL;
    if(*headRef==NULL){
        //newnode->next=NULL;
        *headRef=newnode;
        //return;
    }
    else{
        struct node *temp;
        temp=*headRef;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
