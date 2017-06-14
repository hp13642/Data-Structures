//Simple method is to using logic of merge sort and counting pairs while merging two sorted sub array
//Time Complexity O(nlogn)


#include <iostream>
using namespace std;


int Merge(int *a, int low, int high, int mid)
{
    int i, j, k, c[100];
    i = low;
    k = low;
    j = mid+1;
    int countInv=0;
    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])
        {
            c[k] = a[i];
            k++;
            i++;
        }
        else
        {
            countInv+=(mid-i+1);
            c[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        
        c[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k] = a[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        a[i] = c[i];
    }
    return countInv;
}

int MergeSort(int a[],int l,int r){
    int countInv=0;
    int mid;
    if(l<r){
        mid=(l+r)/2;
        countInv+=MergeSort(a,l,mid);
        countInv+=MergeSort(a,mid+1,r);
        countInv+=Merge(a,l,r,mid);
    }
    return countInv;
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
	    int count_Inversion=MergeSort(a,0,n-1);
	    cout<<count_Inversion<<endl;
	}
	return 0;
}
