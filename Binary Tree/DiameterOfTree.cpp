//Finding Diameter of a given Binary Tree
/*
The diameter of a tree T is the largest of the following quantities:

* the diameter of T’s left subtree
* the diameter of T’s right subtree
* the longest path between leaves that goes through the root of T (this can be computed from the heights of the subtrees of T)
*/

/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

/* Computes the diameter of binary tree with given root.  */
int height(Node* node)
{
    if(!node)
        return 0;
    else
        return 1+max(height(node->left),height(node->right));
}
int diameter(Node* node)
{
    if(!node)
        return 0;
    //Finding height of left and right subtree recursively
    int lheight = height(node->left);
    int rheight = height(node->right);
    //Finding diameter in left and right subtree
    //It may be the case that max distance between two node can be on same side
    //so finding left and right diameter recursively
    //In the end diameter will be maximum of three
    int ldiameter = diameter(node->left);
    int rdiameter = diameter(node->right);
    return max(lheight+rheight+1,max(ldiameter,rdiameter));
}
