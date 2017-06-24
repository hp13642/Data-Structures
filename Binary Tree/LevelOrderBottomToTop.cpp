/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
In following Binary Tree
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
*/
int getMaxLevel(TreeNode* root){
        if(!root)
            return 0;
        else
            return 1+max(getMaxLevel(root->left),getMaxLevel(root->right));
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int levels=getMaxLevel(root);
        stack<vector<int>> tempStack;
        vector<vector<int>> levelOrderRev(levels);
        if(!root)
            return levelOrderRev;
        queue<TreeNode *> Q;
        Q.push(root);
        int count;
        while(!Q.empty()){
            count=Q.size();
            vector<int> res;
            while(count--){
                TreeNode *temp=Q.front();
                res.push_back(temp->val);
                Q.pop();
                if(temp->left)
                    Q.push(temp->left);
                if(temp->right)
                    Q.push(temp->right);
            }
            tempStack.push(res);
        }
        int level=0;
        while(!tempStack.empty()){
            levelOrderRev[level++]=tempStack.top();
            tempStack.pop();
        }
        return levelOrderRev;
    }

