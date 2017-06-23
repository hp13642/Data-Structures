//In a given BST print all nodes that have value between given range of value

/* The structure of a BST Node is as follows:
struct Node 
{
    int data;
    Node * right, * left;
}; */

void printNearNodes(Node *root, int l, int h)
{
    if(!root)
        return;
    if(root->data>l)
        printNearNodes(root->left,l,h);
    if(root->data>=l && root->data<=h)
        cout<<root->data<<" ";
    if(root->data<h)
        printNearNodes(root->right,l,h);
}
