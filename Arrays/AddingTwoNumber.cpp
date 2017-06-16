//Adding two numbers saved in two array from msb to lsb
//result is saved into another result array

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
	    ll n1,n2;
	    s(n1)
	    s(n2)
	    ll m=max(n1,n2);
	    ll a[m],b[m],result[m+1];
	    memset(a,0,sizeof(a));
	    memset(b,0,sizeof(b));
	    for(ll i=m-n1;i<m;i++){
	        s(a[i]);
	    }
	    for(ll i=m-n2;i<m;i++){
	        s(b[i]);
	    }
	    ll carr=0,sum;
	    for(ll i=m-1;i>=0;i--){
	        sum=a[i]+b[i]+carr;
	        if(sum>9){
	            sum-=10;
	            carr=1;
	        }
	        else
	            carr=0;
	        result[i+1]=sum;
	    }
	    if(carr)
	        result[0]=1;
	    else
	        result[0]=0;
	    for(ll i=0;i<=m;i++){
	        if(i==0 && result[i]==0)
	            continue;
	        if(i<m)
	            cout<<result[i]<<" ";
	        else
	            cout<<result[i];
	    }
	    cout<<endl;
	}
	return 0;
}
