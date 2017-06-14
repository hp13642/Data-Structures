/*
Problem Statement-
Given an unsorted array arr[0..n-1] of size n, find the minimum length subarray arr[s..e] such that sorting this subarray makes the 
whole array sorted.
Solution Approach-
a) Scan from left to right and find the first element which is greater than the next element. Let s be the index of such an element.
b) Scan from right to left and find the first element (first in right to left order) which is smaller than the next element let e
  is such final index
if(s<e)
a) Find the minimum and maximum values in arr[s..e]. Let minimum and maximum values be min and 
b) Find the first element (if there is any) in arr[0..s-1] which is greater than min, change s to index of this element. 
c) Find the last element (if there is any) in arr[e+1..n-1] which is smaller than max, change e to index of this element.
else
  s=0 and e=0 i.e array is already sorted
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
	    ll a[n];
	    for(ll i=0;i<n;i++)
	        s(a[i])
	    ll l=0,r=n-1;
	    while(a[l+1]>a[l] && l<n-1)
	        l++;
	    while(a[r-1]<a[r] && r>0)
	        r--;
	    bool f=false;
	    if(l<r){
	        f=true;
	        ll min=a[l],max=a[l];
	    for(ll i=l+1;i<=r;i++){
	        if(a[i]>max)
	            max=a[i];
	        else if(a[i]<min)
	            min=a[i];
	    }
	    while(a[l]>min && l>=0)
	        l--;
	    while(a[r]<max && r<n)
	        r++;
	    }
	    if(f)
	        cout<<l+1<<" "<<r-1<<endl;
	    else
	        cout<<"0"<<" "<<"0"<<endl;
	}
	return 0;
}
