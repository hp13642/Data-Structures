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
        vector<int> preorder;
        if(!root)
            return preorder;
        stack<TreeNode *> st;
        while(1){
            while(root){
               //Process current node
               preorder.push_back(root->val);
                st.push(root);
                //If left subtree exist add to stack
                root=root->left;
            }
            if(st.empty())
                break;
            root=st.top();
            st.pop();
            //indicate completion of left subtree and current node now got to right subtree
            root=root->right;
        }
        return preorder;
    }
};
