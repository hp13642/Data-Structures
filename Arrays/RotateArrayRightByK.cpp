//Rotate an array of n elements to the right by k steps.

//For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].




 void rotate(vector<int>& nums, int k) {
        stack<int> st;
        int i,n=nums.size();
        if(k>=n)
            k=k%n;
        if(n==1 || k==0)
            return;
        for(int i=n-1;i>n-k-1;i--)
            st.push(nums[i]);
        for(i=n-k-1;i>=0;i--){
            nums[i+k]=nums[i];
        }
        for(i=0;i<k;i++){
            int t=st.top();
            st.pop();
            nums[i]=t;
        }
    }
