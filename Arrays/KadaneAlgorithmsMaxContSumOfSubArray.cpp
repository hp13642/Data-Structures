//Maintaing a maxsum and current sum variables if current sum becomes less than zero then set current sum to zero
//Time complexity O(n)

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    int sum=a[0],max=a[0];
	    for(int i=1;i<n;i++){
	        if(sum>max)
	            max=sum;
	        if(sum<0)
	            sum=a[i];
	        else
	            sum+=a[i];
	    }
	    if(sum>max)
	        max=sum;
	    cout<<max<<endl;
	}
	return 0;
}
