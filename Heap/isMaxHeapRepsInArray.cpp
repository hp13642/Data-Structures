//Given an heap in array representation validate that either it is max heap or not.

#include<bits/stdc++.h>
using namespace std;

int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> a(n);
	    for(int i=0;i<n;i++)cin>>a[i];
	    bool flag=true;
	    for(int i=0;i<n/2;i++){
	        int l=2*i+1;
	        int r=2*i+2;
	        if((l<n && a[i] < a[l])||((r<n && a[i] < a[r]))){
	            flag=false;
	            break;
	        }
	    }
	    if(flag)
	        cout<<"1"<<endl;
	    else
	        cout<<"0"<<endl;
	}
	return 0;
}
