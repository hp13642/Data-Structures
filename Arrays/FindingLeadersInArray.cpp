/*
Problem Statement-
Finding LEADERS in the array. An element is leader if it is greater than all the elements to its right side.
 And the rightmost element is always a leader
Solution approach-
Scan all the elements from right to left in array and keep track of maximum till now. When maximum changes it’s value, print it.
Time Complexity O(n)
*/


#include <iostream>
using namespace std;
void printLeader(int a[],int ind,int max){
    if(ind>=0){
        int m;
        if(a[ind]>max)
            m=a[ind];
        else
            m=max;
        printLeader(a,ind-1,m);
        if(a[ind]>max)
            cout<<a[ind]<<" ";
    }
    else
        return;
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    printLeader(a,n-1,a[n-1]-1);
	    cout<<endl;
	}
	return 0;
}
