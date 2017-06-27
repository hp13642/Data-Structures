/*
Problem Statement-
Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
*/



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
    int sumOfLeftLeaves1(TreeNode* root,char ch){
        if(!root)
            return 0;
        if(root->left==NULL && root->right==NULL){
            if(ch=='L')
                return root->val;
            else
                return 0;
        }
        else if(root->left==NULL)
            return sumOfLeftLeaves1(root->right,'R');
        else if(root->right==NULL)
            return sumOfLeftLeaves1(root->left,'L');
        else
            return sumOfLeftLeaves1(root->left,'L') + sumOfLeftLeaves1(root->right,'R');
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root || (root->left==NULL && root->right==NULL))
            return 0;
        return sumOfLeftLeaves1(root->left,'L') + sumOfLeftLeaves1(root->right,'R');
    }
};
