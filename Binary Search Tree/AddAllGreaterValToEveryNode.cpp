/*
Problem Statement-
Given a Binary Search Tree (BST), modify it so that all greater values in the given BST are added to every node. For example

              50
           /      \
         30        70
        /   \      /  \
      20    40    60   80 

The above tree should be modified to following 

              260
           /      \
         330        150
        /   \       /  \
      350   300    210   80



*/

/* BST Node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

/*  modifies the root of the bst */
void AddValue(Node *root,int *sum){
    if (root == NULL)  return;
 
    // Recur for right subtree
    AddValue(root->right, sum);
    // Now *sum has sum of nodes in right subtree, add
    // root->data to sum and update root->data
    *sum = *sum + root->data;
    root->data = *sum;
 
    // Recur for left subtree
    AddValue(root->left, sum);
}
void modify(Node **root)
{
    int sum=0;
    AddValue(*root,&sum);
}
