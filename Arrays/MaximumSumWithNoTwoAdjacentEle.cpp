/*
Problem Statement-
Given an array of positive numbers,
find the maximum sum of a subsequence with the constraint that no 2 numbers in the sequence should be adjacent in the array.
Solution Approach-
Loop for all elements in arr[] and maintain two sums incl and excl where incl = Max sum including the previous element 
and excl = Max sum excluding the previous element.
Max sum excluding the current element will be max(incl, excl) and max sum including the current element will be excl + current element 
(Note that only excl is considered because elements cannot be adjacent).
At the end of the loop return max of incl and excl.

Time Complexity- O(n)
*/






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
	    int curr=a[0],prev=0,temp=0;
	    for(int i=1;i<n;i++){
	        temp=(curr>prev)?curr:prev;
	        curr=prev+a[i];
	        prev=temp;
	    }
	    temp=(curr>prev)?curr:prev;
	    cout<<temp<<endl;
	}
	return 0;
}
