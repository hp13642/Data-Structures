//Problem Statement-Given an array where elements are sorted in ascending order, convert it to a height balanced BST.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBSTUtil(vector<int>& nums,int start,int end){
        if(start==end){
            int mid=(start+end)/2;
            struct TreeNode *root=(struct TreeNode*)malloc(sizeof(struct TreeNode));
            root->val=nums[mid];
            root->left=NULL;
            root->right=NULL;
            return root;
        }
        else if(start<end){
            int mid=ceil((start+end)/2.0);
            struct TreeNode *root=(struct TreeNode*)malloc(sizeof(struct TreeNode));
            root->val=nums[mid];
            root->left=sortedArrayToBSTUtil(nums,start,mid-1);
            root->right=sortedArrayToBSTUtil(nums,mid+1,end);
            return root;
        }
        else
            return NULL;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return NULL;
        return sortedArrayToBSTUtil(nums,0,n-1);
    }
};
