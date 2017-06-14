//Using a bucket and maintaining a count of majority element
//and second pass check either that element present more than half time or not
//Running time complexity O(n)

#include <bits/stdc++.h>
#define s(x) scanf("%d",&x);
using namespace std;

int main() {
	int t;
	s(t);
	while(t--){
	    int n;
	    s(n);
	    int a[n],temp,no=INT_MIN;
	    int c=0,mid=floor(n/2)+1;
	    for(int i=0;i<n;i++){
	        s(a[i]);
	        temp=a[i];
	       if(no==INT_MIN || temp==no){
	            no=temp;
	            c++;
	        }
	        else{
	            c--;
	            if(c<0)
	                no=temp;
	        }
	    }
	    int count=0;
	    for(int i=0;i<n;i++){
	        if(a[i]==no)
	            count++;
	    }
	        
	    if(count<mid)
	        cout<<"NO Majority Element"<<endl;
	    else
	        cout<<no<<endl;
	}
	return 0;
}
