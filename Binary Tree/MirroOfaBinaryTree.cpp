//Writting an efficient way to converta binary tree into its mirror image

/* A binary tree node has data, pointer to left child
   and a pointer to right child /
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

/* Should convert tree to its mirror */
void mirror(Node* node) 
{
    if(!node)
        return;
    else{
        mirror(node->left);
        mirror(node->right);
        Node *temp=node->left;
        node->left=node->right;
        node->right=temp;
    }
}
