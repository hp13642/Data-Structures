//Converting a binary tree to doubly linked list

/* Structure for tree and linked list
struct Node
{
    int data;

    // left is used as previous and right is used
    // as next in DLL
    Node *left, *right;
}; */

// This function should convert a given Binary tree to Doubly
// Linked List
// root --> Root of Binary Tree
// head_ref --> Pointer to head node of created doubly linked list

void BToDLL(Node *root, Node **head_ref)
{
    // Base cases
    if (root == NULL)
        return;
 
    // Recursively convert right subtree
    BToDLL(root->right, head_ref);
 
    // insert root into DLL
    root->right = *head_ref;
 
    // Change left pointer of previous head
    if (*head_ref != NULL)
        (*head_ref)->left = root;
 
    // Change head of Doubly linked list
    *head_ref = root;
 
    // Recursively convert left subtree
    BToDLL(root->left, head_ref);
}

