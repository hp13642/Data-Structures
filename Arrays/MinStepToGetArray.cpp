/*
Problem Statement-
Consider an array with n elements and value of all the elements is zero. We can perform following operations on the array.
Incremental operations:Choose 1 element from the array and increment its value by 1.
Doubling operation: Double the values of all the elements of array.
Solution Approach-
Take the target array first. 
Initialize result as 0. 
If all are even, divide all elements by 2 
and increment result by 1. 
Find all odd elements, make them even by 
reducing them by 1. and for every reduction,
increment result by 1.
Finally we get all zeros in target array.
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
	    s(n);
	    ll a[n],min=INT_MIN,step=0;
	    for(ll i=0;i<n;i++){
	        cin>>a[i];
	    }
	    int c=0;
	    while(c!=n){
	        //making all odd numbers in one pass 
	        for(int i=0;i<n;i++){
	            if(a[i]%2){
	                a[i]--;
	                step++;
	                if(a[i]==0)
	                    c++;
	            }
	        }
	        //Now all numbers are even so we can perform second operation
	        //we can devide by 1 to all element and that wil be count as 
	        //single operation
	        for(int i=0;i<n;i++){
	            a[i]/=2;
	        }
	        if(c!=n)
	            step++;
	    }
	    cout<<step<<endl;
	}
	return 0;
}
