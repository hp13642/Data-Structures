//Counting leaves in given Binary Tree

/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

/* Should return count of leaves. For example, return
    value should be 2 for following tree.
         10
      /      \ 
   20       30 */
int countLeaves(Node* root)
{
    if(!root)
        return 0;
    else if(root->left==NULL && root->right==NULL)
        return 1;
    else
        return countLeaves(root->left)+countLeaves(root->right);
}
