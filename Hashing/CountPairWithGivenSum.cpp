/*
Problem Statement-
Given an array of integers, and an integer  ‘K’ , find the count of pairs of elements in the array whose sum is equal to 'K'.
Solution approach-
use map and store count of each element and for each element find (k-ele) in map if search found then increase count by count of (K-ele)
in map and check if current element is already present in map then increase its count if not then insert it map with count 1
Time Complexity-O(n)
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
	    ll n,sum;
	    s(n)
	    s(sum)
	    map<ll,ll> m;
	    map<ll,ll>::iterator it;
	    ll count=0;
	    for(ll i=0;i<n;i++){
	        ll temp;
	        s(temp)
	        it=m.find(sum-temp);
	        ll c=0;
	        if(it!=m.end()){
	            count+=it->second;
	        }
	        if(m.find(temp)!=m.end()){
	                m[temp]++;
	            }
	        else
	           m[temp]=1;
	        
	        
	    }
	    cout<<count<<endl;
	}
	return 0;
}
