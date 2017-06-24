//Finding mimimum depth of a given binary tree-
//The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        else if(root->left==NULL && root->right==NULL)
            return 1;
        else if(root->left==NULL)
            return 1+minDepth(root->right);
        else if(root->right==NULL)
            return 1+minDepth(root->left);
        else
            return 1+min(minDepth(root->left),minDepth(root->right));
    }
