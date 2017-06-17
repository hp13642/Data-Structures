//Given an linked list that contain 0,1 or 2 and we have to sort the linked list in such a way that all 0's appear first then 1's then 2's
//Solution Approach-
//take three head for 0,1 and 2 and three ptr to keep track of last node of all thre linked list
//traverse the given list and correspoding to element insert that node in corresponding linked list
//after traverseing comlete linked list merge all three linked list in order 0 1 and 2
//In the end project back the result in given linked list by copying the element of resulttant single linked list to original one


/*
  Sort the list of 0's,1's and 2's
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
     int data;
     Node *next;
  }

*/

struct Node* createNode(int data){
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=data;
    t->next=NULL;
    return t;
}

void sortList(Node *head)
{
    if(head==NULL || head->next==NULL)
        return;
    struct Node *temp,*t0,*t1,*t2,*t=head,*h0=NULL,*h1=NULL,*h2=NULL,*h;
    while(t!=NULL){
        int d=t->data;
        temp=createNode(d);
        if(d==0){
            if(!h0){
                h0=temp;
                t0=temp;
            }
            else{
                t0->next=temp;
                t0=temp;
            }
        }
        else if(d==1){
            if(!h1){
                h1=temp;
                t1=temp;
            }
            else{
                t1->next=temp;
                t1=temp;
            }
        }
        else{
            if(!h2){
                h2=temp;
                t2=temp;
            }
            else{
                t2->next=temp;
                t2=temp;
            }
        }
        t=t->next;
    }
    if(!h0){
        if(!h1){
            h=h2;
        }
        else{
            h=h1;
            t1->next=h2;
        }
    }
    else{
        h=h0;
        if(!h1){
            t0->next=h2;
        }
        else{
            t1->next=h2;
            t0->next=h1;
        }
        
    }
    t=head;
    t1=h;
    while(t!=NULL && t1!=NULL){
        t->data=t1->data;
        t=t->next;
        t1=t1->next;
    }
    return;
}


