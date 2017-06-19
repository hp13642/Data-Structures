/*
Problem Statement-
Given an array of integers, find length of the largest subarray with sum equals to 0
Solution Approach-
Use Hashing to solve this problem in O(n) time. The idea is to iterate through the array and for every element arr[i], 
calculate sum of elements form 0 to i (this can simply be done as sum += arr[i]). If the current sum has been seen before, 
then there is a zero sum array.
*/

/*You are required to complete this function*/
int maxLen(int A[],int n)
{
    map<int,int> m;
    map<int,int>::iterator it;
    int len=0,sum=0;
    for(int i=0;i<n;i++){
        sum+=A[i];
        if(sum==0)
            len=i+1;
        else{
            it=m.find(sum);
            if(it!=m.end())
                len=max(len,i-it->second);
            else
                m[sum]=i;
        }
    }
    return len;
}
