//Checking either the given tree is height balanced or not i.e. every node should follow AVL property

/* A binary tree node structure
struct Node {
    int data;
    Node* left, * right;
}; */

int height(Node *root){
    if(!root)
        return 0;
    else
        return 1+max(height(root->left),height(root->right));
}
bool isBalanced(Node *root)
{
    if(!root)
        return true;
    int lHeight=height(root->left);
    int rHeight=height(root->right);
    if(abs(lHeight-rHeight)<=1 && isBalanced(root->left) && isBalanced(root->right))
        return true;
    return false;
}
