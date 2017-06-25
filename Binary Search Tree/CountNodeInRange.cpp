//Getting count of all node in given BST whose value lies in a given range [l,r]
//both l and r are inclusive

/*

The structure of a BST node is as follows:

struct Node {
int data;
Node * right, * left;
};


*/
int getCountOfNode(Node *root, int l, int h)
{
    if(!root)
        return 0;
    else if(root->data<=h && root->data>=l)
        return 1+getCountOfNode(root->left,l,h)+getCountOfNode(root->right,l,h);
    else if(root->data<l)
        return getCountOfNode(root->right,l,h);
    else
        return getCountOfNode(root->left,l,h);
}
