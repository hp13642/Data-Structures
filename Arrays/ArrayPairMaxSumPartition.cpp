/*
Problem Statement-
Given an array of 2n integers, your task is to group these integers into n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) 
which makes sum of min(ai, bi) for all i from 1 to n as large as possible.
Solution Approach-
1-Sort the array
2-in order to maximize the sum of min(ai,bi) starting from 0 index each second element makes sum larger
*/

int arrayPairSum(vector<int>& nums) {
        vector<int>::iterator it=nums.begin();
        int N=nums.size();
        sort(it,it+N);
        int maxSum=0;
        for(int i=0;i<N;i+=2){
            maxSum+=nums[i];
        }
        return maxSum;
    }
