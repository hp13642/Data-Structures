/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.

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
    int sumNumbersPath(TreeNode* root,int num){
        if(!root)
            return 0;
        if(root->left==NULL && root->right==NULL)
            return 10*num + root->val;
        else if(root->left==NULL)
            return (sumNumbersPath(root->right,(10*num + root->val)));
        else if(root->right==NULL)
            return (sumNumbersPath(root->left,(10*num + root->val)));
        else{
            return (sumNumbersPath(root->left,(10*num + root->val))) + 
                    (sumNumbersPath(root->right,(10*num + root->val)));
        }
    }
    int sumNumbers(TreeNode* root) {
        return sumNumbersPath(root,0);        
    }
};
