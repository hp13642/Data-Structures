/*
Problem Statement-
Given an array of size n and an integer k, return the of count of distinct numbers in all windows of size k
*/

/*You are required to complete below method */
void countDistinct(int A[], int k, int n)
{
    map<int,int> m;
    map<int,int>::iterator it;
    int count=0;
    for(int i=0;i<k;i++){
        if(m.find(A[i])!=m.end())
            m[A[i]]++;
        else{
            m[A[i]]=1;
            count++;
        }
    }
    if(k!=n)
        cout<<count<<" ";
    else
        cout<<count;
    for(int i=k;i<n;i++){
        //If current element is present then increase cout else not
        if(m.find(A[i])!=m.end()){
            m[A[i]]++;
        }
        else{
            m[A[i]]=1;
            count++;
        }
        //Erasing first element of previous window
        if(m[A[i-k]]==1){
            count--;
            m.erase(A[i-k]);
        }
        else
            m[A[i-k]]--;
        if(i<n-1)
            cout<<count<<" ";
        else
            cout<<count;
    }
}
