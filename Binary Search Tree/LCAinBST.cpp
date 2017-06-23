//Finding LCA of given two keys in a Binary Search Tree

/*The structure of a BST Node is as follows:
struct Node {
    int data;
    Node * right, * left;
};*/

/*You are required to complete
this function*/
Node* LCA(Node *root, int n1, int n2)
{
    //if lca will exist in left subtree
    if(n1<root->data && n2<root->data)
        return LCA(root->left,n1,n2);
    //if lca will exist in right subtree
    else if(n1>root->data && n2>root->data)
        return LCA(root->right,n1,n2);
    //if both keys lies on diff sides of curr node 
    return root;
}
