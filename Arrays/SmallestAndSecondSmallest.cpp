//Finding smallest and second smallest element in an array in no any such element is found then printing -1
//done in single pass
//Time Complexity O(n)


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
	    ll min1=1001,min2=1001;
	    for(ll i=0;i<n;i++){
	        s(a[i])
	        if(a[i]<min1){
	            min2=min1;
	            min1=a[i];
	        }
	        else if(a[i]==min1)
	            continue;
	        else if(a[i]<min2)
	            min2=a[i];
	    }
	    if(min2!=1001)
	        cout<<min1<<" "<<min2<<endl;
	    else
	        cout<<"-1"<<endl;
	}
	return 0;
}
