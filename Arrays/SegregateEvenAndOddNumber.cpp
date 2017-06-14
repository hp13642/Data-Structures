//Segregate Even and Odd number in an array and sort them in natural order all odd number are followed by all even numbers and
//even and odd numbers are seprately in sorted order
//Solution approach-
//take two index one from left and one from right side while taking input place even number from left side and odd number from right side
//Then sort the left part of array that contain even numbers and then sort right part of array that contain odd array

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
	    ll l=0,r=n;
	    for(ll i=0;i<n;i++){
	        ll temp;
	        s(temp)
	        if(temp%2==0)
	            a[l++]=temp;
	        else
	            a[--r]=temp;
	    }
	    sort(a,a+l);
	    sort(a+l,a+n);
	    for(ll i=0;i<n;i++){
	        if(i<n-1)
	            cout<<a[i]<<" ";
	        else
	            cout<<a[i];
	    }
	    cout<<endl;
	}
	return 0;
}
