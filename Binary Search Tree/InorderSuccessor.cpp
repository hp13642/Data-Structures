//Finding inorder successor of a given node in binary search tree
/*
Algorithm-
1) If right subtree of node is not NULL, then succ lies in right subtree. Do following.
Go to right subtree and return the node with minimum key value in right subtree.
2) If right sbtree of node is NULL, then start from root and us search like technique. Do following.
Travel down the tree, if a node’s data is greater than root’s data then go right side, otherwise go to left side.
*/

/*The structure of Node
struct Node {
int data;
Node * right, * left;
};*/

/* The below function should return the node which is 
inorder successor of given node x. */

//Finding minimum value Node
Node * minValue(Node *root){
    if(root->left==NULL)
        return root;
    else
        return minValue(root->left);
}
Node * inOrderSuccessor(Node *root, Node *n)
{
    //if rightsubtree of given node is not empty then
    if( n->right != NULL )
        return minValue(n->right);
 
    struct Node *succ = NULL;
 
    // Start from root and search for successor down the tree
    while (root != NULL)
    {
        if (n->data < root->data)
        {
            succ = root;
            root = root->left;
        }
        else if (n->data > root->data)
            root = root->right;
        else
           break;
    }
 
    return succ;
}
