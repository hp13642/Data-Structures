/*
Problem Statement-
Given an array and a number x, find if there is a pair with product equal to x.
Solution Approach-
Create an empty hash table
1-Traverse array elments and do following for every element arr[i].
2-If arr[i] is 0 and x is also 0, return true, else ignore arr[i].
    If x % arr[i] is 0 and x/arr[i] exists in table, return true.
    Insert arr[i] into the hash table.
Return false

Note- Handle case when element of array is equal to zero id product is also zero return true else dont insert zero in hash table

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
	    ll n,prod;
	    s(n)
	    s(prod)
	    multimap<ll,ll> m;
	    bool f=true;
	    for(ll i=0;i<n;i++){
	        ll temp;
	        s(temp)
	        if(temp==0 && prod==0)
	            f=false;
	        if(f){
	            if(temp!=0 && prod%temp==0){
	                if(m.find(prod/temp)!=m.end())
	                    f=false;
	            }
	            m.insert({temp,1});
	        }
	    }
	    if(!f)
	        cout<<"Yes"<<endl;
	    else
	        cout<<"No"<<endl;
	}
	return 0;
}
