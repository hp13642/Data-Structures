/*
Problem Statement-
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left 
for the next level and alternate between).
    3
   / \
  9  20
    /  \
   15   7
its zigzag level order traversal(OR Spiral order traversal) will be 
[
  [3],
  [20,9],
  [15,7]
]
*/

int getMaxLevel(TreeNode* root){
        if(!root)
            return 0;
        else
            return 1+max(getMaxLevel(root->left),getMaxLevel(root->right));
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int levels=getMaxLevel(root);
        vector<vector<int>> spiralLevelOrder(levels);
        if(!root)
            return spiralLevelOrder;
        deque<TreeNode *> Q;
        stack<int> st;
        Q.push_back(root);
        int level=0,count;
        bool leftFlag=false;
        while(!Q.empty()){
            count=Q.size();
            while(count--){
                TreeNode *temp;
                temp=Q.front();
                Q.pop_front();
                if(leftFlag)
                    st.push(temp->val);
                else
                    spiralLevelOrder[level].push_back(temp->val);
                if(temp->left)
                    Q.push_back(temp->left);
                if(temp->right)
                    Q.push_back(temp->right);
            }
            while(!st.empty()){
                int t1=st.top();
                st.pop();
                spiralLevelOrder[level].push_back(t1);
            }
            level++;
            leftFlag=!leftFlag;
        }
        return spiralLevelOrder;
    }
