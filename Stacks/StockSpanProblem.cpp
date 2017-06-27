/*
Problem Statement-
The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate span of 
stock’s price for all n days. 
The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day, 
for which the price of the stock on the current day is less than or equal to its price on the given day.
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
	    ll res[n];
	    ll temp;
	    stack<pair<ll,ll>> st;
	    for(ll i=0;i<n;i++){
	        cin>>temp;
	        if(st.empty() || temp < st.top().first){
	            st.push({temp,1});
	            res[i]=1;
	        }
	        else{
	            ll c=0;
	            while((!st.empty()) && temp >= st.top().first){
	                c+=st.top().second;
	                st.pop();
	            }
	            st.push({temp,c+1});
	            res[i]=c+1;
	        }
	    }
	    for(ll i=0;i<n;i++){
	        if(i<n-1)
	            cout<<res[i]<<" ";
	        else
	            cout<<res[i]<<endl;
	    }
	}
	return 0;
}
