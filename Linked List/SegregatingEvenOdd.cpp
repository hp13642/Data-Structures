/*
Problem Statement-
Segregating even number followed by odd number preserving order of even and odd number
Solution Approach-
while taking input maintain two linked list one contain even number and other containg odd number
and in the end connect last node of even numbers linked list to odd numbers linked list
*/
#include<bits/stdc++.h>
#define ll long long int
#define s(x) scanf("%lld",&x);
#define p(x) printf("%lld",x);
#define enter printf("\n");
#define space printf(" ");
struct Node{
    ll data;
    struct Node *next;
};
struct Node* createNode(int data){
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=data;
    t->next=NULL;
    return t;
}
using namespace std;
int main()
 {
	ll t;
	s(t)
	while(t--){
	    ll n;
	    s(n)
	    //Input Linked List
	     //Logic for segregating even and odd number
	    struct Node *head,*headEven=NULL,*headOdd=NULL,*t1,*t2,*t3;
	    for(ll i=0;i<n;i++){
	        ll temp;
	        s(temp)
	        t1=createNode(temp);
	        if(temp%2==0){
	            if(!headEven){
	                headEven=t1;
	                t2=t1;
	            }
	            else{
	                t2->next=t1;
	                t2=t1;
	            }
	        }
	        else{
	            if(!headOdd){
	                headOdd=t1;
	                t3=t1;
	            }
	            else{
	                t3->next=t1;
	                t3=t1;
	            }
	        }
	        
	        
	    }
	     
	    t2->next=headOdd;
	    //Printing Linked List
	    t1=headEven;
	    while(t1!=NULL){
	        if(t1->next!=NULL)
	            cout<<t1->data<<" ";
	        else
	            cout<<t1->data;
	        t1=t1->next;
	    }
	    cout<<endl;
	}
	return 0;
}
