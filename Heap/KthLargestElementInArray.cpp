//Finding Kth largest element in a given unsorted array

int findKthLargest(vector<int>& nums, int k) {
        //Min heap
        priority_queue<int,vector<int>,greater<int>> pq;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(pq.empty() || pq.size()<k)
                pq.push(nums[i]);
            else{
                if(nums[i] > pq.top()){
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }
        return pq.top();
    }
