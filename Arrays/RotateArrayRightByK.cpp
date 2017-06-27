//Rotate an array of n elements to the right by k steps.

//For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].



//in O(n) using O(k) extra space
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


//In Java using constant space
public void rotate(int[] nums, int k) {

    if(nums == null || nums.length < 2){
        return;
    }
    
    k = k % nums.length;
    reverse(nums, 0, nums.length - k - 1);
    reverse(nums, nums.length - k, nums.length - 1);
    reverse(nums, 0, nums.length - 1);
    
}

private void reverse(int[] nums, int i, int j){
    int tmp = 0;       
    while(i < j){
        tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
        i++;
        j--;
    }
}
