/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
*/

class Solution {
public:
    void hasPathSum(TreeNode* root, int sum,vector< vector<int> >&paths,vector<int> &s) {
        if(!root)
            return;
        s.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            if(sum==root->val){
                paths.push_back(s);
                return;
            }
            else
                return;
        }
        else if(root->left==NULL){
            hasPathSum(root->right,sum-root->val,paths,s);
            s.pop_back();
        }
        else if(root->right==NULL){
            hasPathSum(root->left,sum-root->val,paths,s);
            s.pop_back();
        }
        else{
            hasPathSum(root->left,sum-root->val,paths,s);
            s.pop_back();
            hasPathSum(root->right,sum-root->val,paths,s);
            s.pop_back();
        }
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector< vector<int> >paths;
        vector<int> s;
        int len=0;
        hasPathSum(root,sum,paths,s);
        return paths;
    }
};
