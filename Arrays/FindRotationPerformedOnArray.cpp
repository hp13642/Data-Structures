/*
Problem Statement-
Consider an array of distinct numbers sorted in increasing order. The array has been rotated (anti-clockwise) k number 
of times. Given such an array, find the value of k.

The IDEA is using binary search to find minimum element in array
In following program getPivot function returns the index of minimum element of array after rotation in O(logn) times
*/

#include<bits/stdc++.h>
using namespace std;
int getPivot(vector<int> &a,int l,int r){
    if(r<=l)
        return l;
    int mid=(l+r)/2;
    if(mid < r && a[mid] > a[mid+1])
        return mid+1;
    if(l < mid && a[mid-1] > a[mid])
        return mid;
    if(a[mid] < a[r])
        return getPivot(a,l,mid-1);
    else
        return getPivot(a,mid+1,r);
}

int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> a(n);
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    cout<<getPivot(a,0,n-1)<<endl;
	}
	return 0;
}
