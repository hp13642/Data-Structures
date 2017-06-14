/*
Problem Statement-
Given an array A[] having n positive elements. The task to create another array B[] such as 
B[i] is XOR of all elements of array A[] except A[i].
Solution Approach-
1-with initialization of temp=0 once go from left side and store xor of all element excluding curr element
2-again with initialization of temp=0 once come from right side and store xor of all element excluding curr element
*/

#include<bits/stdc++.h>
#define ll long long int
#define s(x) scanf("%lld",&x);
#define p(x) printf("%lld",x);
#define enter printf("\n");
#define space printf(" ");
using namespace std;
int main()
 {
	ll t;
	s(t)
	while(t--){
	    ll n;
	    s(n)
	    ll a[n],Xor[n];
	    for(ll i=0;i<n;i++)
	        s(a[i])
	    ll temp=0;
	    //Finding Xor of all element i.e left side to i and save them in ith
	    //index of answer array i.e Xor[]
	    for(ll i=0;i<n;i++){
	        Xor[i]=temp;
	        temp^=a[i];
	    }
	    //Finding Xor of all element i.e right side to i and save them in ith
	    //index of answer array i.e Xor[]
	    //Thus effect of both loops will be as at index i value of xor of all
	    //element of array will be present except ith element
	    temp=0;
	    for(ll i=n-1;i>=0;i--){
	        Xor[i]^=temp;
	        temp^=a[i];
	    }
	    for(ll i=0;i<n;i++){
	        if(i<n-1)
	            cout<<Xor[i]<<" ";
	        else
	            cout<<Xor[i];
	    }
	    cout<<endl;
	}
	return 0;
}
