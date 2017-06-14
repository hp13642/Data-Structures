//Segregate Even and Odd number in an array and sort them in natural order all odd number are followed by all even numbers and
//even and odd numbers are seprately in sorted order
//Solution approach-
//take two index one from left and one from right side while taking input place even number from left side and odd number from right side
//Then sort the left part of array that contain even numbers and then sort right part of array that contain odd array
//Time Complexity O(nlogn)


/*Method-2
In this method odd and even numbr segregate but they might can not be in sorted order
1) Initialize two index variables left and right:  
            left = 0,  right = size -1 
2) Keep incrementing left index until we see an odd number.
3) Keep decrementing right index until we see an even number.
4) If lef < right then swap arr[left] and arr[right]
Time Complexity O(n)
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
	    ll a[n];
	    ll l=0,r=n;
	    for(ll i=0;i<n;i++){
	        ll temp;
	        s(temp)
	        if(temp%2==0)
	            a[l++]=temp;
	        else
	            a[--r]=temp;
	    }
	    sort(a,a+l);
	    sort(a+l,a+n);
	    for(ll i=0;i<n;i++){
	        if(i<n-1)
	            cout<<a[i]<<" ";
	        else
	            cout<<a[i];
	    }
	    cout<<endl;
	}
	return 0;
}



//Code for Method-2
void segregateEvenOdd(int arr[], int size)
{
    /* Initialize left and right indexes */
    int left = 0, right = size-1;
    while (left < right)
    {
        /* Increment left index while we see 0 at left */
        while (arr[left]%2 == 0 && left < right)
            left++;
 
        /* Decrement right index while we see 1 at right */
        while (arr[right]%2 == 1 && left < right)
            right--;
 
        if (left < right)
        {
            /* Swap arr[left] and arr[right]*/
            swap(&arr[left], &arr[right]);
            left++;
            right--;
        }
    }
}

