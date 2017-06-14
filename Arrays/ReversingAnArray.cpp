//Reversing an array of Size n
//Simply done in a single pass by taking two indexes one left and one right and swaping the element corresponding to them
//and incrementing left index and decrementing right index

#include <iostream>
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
	    int l=0,r=n-1;
	    while(l<r){
	        int temp=a[r];
	        a[r]=a[l];
	        a[l]=temp;
	        l++;
	        r--;
	    }
	    for(int i=0;i<n;i++)
	        cout<<a[i]<<" ";
	    cout<<endl;
	}
	return 0;
}
