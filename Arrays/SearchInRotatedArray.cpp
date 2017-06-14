//Key Idea are :
/*
1) Find middle point mid = (l + h)/2
2) If key is present at middle point, return mid.
3) Else If arr[l..mid] is sorted
    a) If key to be searched lies in range from arr[l]
       to arr[mid], recur for arr[l..mid].
    b) Else recur for arr[mid+1..r]
4) Else (arr[mid+1..r] must be sorted)
    a) If key to be searched lies in range from arr[mid+1]
       to arr[r], recur for arr[mid+1..r].
    b) Else recur for arr[l..mid]
*/
//Running Time=O(logn)

#include <iostream>
using namespace std;

int newSearch(int a[],int l,int r,int item){
    if(l<r){
        int mid=(l+r)/2;
        if(a[mid]==item)
            return mid;
        else{
            int temp=newSearch(a,l,mid,item);
            if(temp==-1)
                return newSearch(a,mid,r,item);
            else
                return temp;
        }
        //return -1;
    }
    else if(l==r && a[l]==item)
        return l;
    else
        return -1;
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
	    int item;
	    cin>>item;
	    int res=newSearch(a,0,n-1,item);
	    cout<<res<<endl;
	        
	}
	return 0;
}
