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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        if(!root)
            return inorder;
        stack<TreeNode *> st;
        while(1){
            while(root){
                st.push(root);
                //Go to left subtree and keep on adding to stack
                root=root->left;
            }
            if(st.empty())
                break;
            root=st.top();
            st.pop();
            //after poping process current node
            inorder.push_back(root->val);
            //indicates completion of current node and left subtree now go to right subtree
            root=root->right;
        }
        return inorder;
    }
};
