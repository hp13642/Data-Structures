/*
Problem Statement-
Return an array that contains largest value in each row of a binary tree As in following tree
          1
         / \
        3   2
       / \   \  
      5   3   9 

Output: [1, 3, 9]
*/


vector<int> largestValues(TreeNode* root) {
        vector<int> maxEleInEachRow;
        if(!root)
        return maxEleInEachRow;
        queue<TreeNode *> Q;
        Q.push(root);
        int count;
        while(!Q.empty()){
            count=Q.size();
            int max=INT_MIN;
            while(count--){
                TreeNode *temp=Q.front();
                Q.pop();
                if(temp->val>max)
                    max=temp->val;
                if(temp->left)
                    Q.push(temp->left);
                if(temp->right)
                    Q.push(temp->right);
            }
            maxEleInEachRow.push_back(max);
        }
        return maxEleInEachRow;
    }
