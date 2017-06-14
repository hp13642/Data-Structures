//Problem- Given an integer array, you need to find the two elements such that their sum is closest to zero.
//Solving using sorting 
//Time Complexity O(nlogn)


#include<bits/stdc++.h>
#define ll long long int
#define s(x) scanf("%lld",&x)
#define p(x) printf("%lld",x)
#define enter printf("\n")
#define space printf(" ")
using namespace std;
int main()
 {
	ll t;
	s(t);
	while(t--){
	    ll n;
	    s(n);
	    ll a[n];
	    for(ll i=0;i<n;i++){
	        s(a[i]);
	    }
	    sort(a,a+n);
	    ll l=0,r=n-1,min=INT_MAX,a1,b1;
	    while(l<r){
	        if(abs(a[l]+a[r])<min){
	            a1=l;
	            b1=r;
	            min=abs(a[l]+a[r]);
	        }
	        if(a[l]+a[r]<0)
	            l++;
	        else
	            r--;
	    }
	    p(a[a1]);
	    space;
	    p(a[b1]);
	    enter;
	}
	return 0;
}
