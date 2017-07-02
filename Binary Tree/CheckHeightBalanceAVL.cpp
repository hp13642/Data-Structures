/*
Given a binary tree, determine if it is height-balanced.
For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never 
differ by more than 1
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
    int getHeightCheck(TreeNode* root,int *f){
        if(!root)
            return 0;
        else{
            int l=1+getHeightCheck(root->left,f);
            int r=1+getHeightCheck(root->right,f);
            if(abs(l-r)>1)
                *f=0;
            return max(l,r);
        }
            
    }
    bool isBalanced(TreeNode* root) {
        int f=1;
        int r=getHeightCheck(root,&f);
        if(!f)
            return false;
        else
            return true;
    }
};
