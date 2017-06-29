/*
Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. 
The time complexity must be in O(n).
For example-
[2,1,1] return 2
[1,3,2] return 3
[2,2,3,1] return 1
*/
int thirdMax(vector<int>& nums) {
        priority_queue<int,vector<int>> pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        if(pq.size()<3)
            return pq.top();
        else{
            int max=pq.top();
            int x1=pq.top();
            while(pq.top()==x1 && (!pq.empty())) pq.pop();
            int x2=pq.top();
            while(pq.top()==x2 && (!pq.empty())) pq.pop();
            if(pq.empty())
                return max;
            else
                return pq.top();
        }
    }
