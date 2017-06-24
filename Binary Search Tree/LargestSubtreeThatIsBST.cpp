/*
Problem Statement-
Given a Binary Tree, write a function that returns the size of the largest subtree which is also a Binary Search Tree (BST). 
If the complete Binary Tree is BST, then return the size of whole tree.

*/

//Method-1
//Inefficient
//Running time O(n^2)
int largestBST(struct node *root)
{
   if (isBST(root))
     return size(root); 
   else
    return max(largestBST(root->left), largestBST(root->right));
}

//Method-2
//Efficient
//Running time - O(n)
/* Tree node structure  used in the program
 struct Node
 {
     int data;
     struct Node* left, *right;
};*/

/*You are required to complete this method */
int largestBSTRe(Node* node, int *min_ref, int *max_ref,
                            int *max_size_ref, bool *is_bst_ref){
    /* Base Case */
  if (node == NULL)
  {
     *is_bst_ref = 1; // An empty tree is BST
     return 0;    // Size of the BST is 0
  }
 
  int min = INT_MAX;
 
  /* A flag variable for left subtree property
     i.e., max(root->left) < root->data */
  bool left_flag = false;
 
  /* A flag variable for right subtree property
     i.e., min(root->right) > root->data */
  bool right_flag = false;
 
  int ls, rs; // To store sizes of left and right subtrees
 
  /* Following tasks are done by recursive call for left subtree
    a) Get the maximum value in left subtree (Stored in *max_ref)
    b) Check whether Left Subtree is BST or not (Stored in *is_bst_ref)
    c) Get the size of maximum size BST in left subtree (updates *max_size) */
  *max_ref = INT_MIN;
  ls = largestBSTRe(node->left, min_ref, max_ref, max_size_ref, is_bst_ref);
  if (*is_bst_ref == 1 && node->data > *max_ref)
     left_flag = true;
 
  /* Before updating *min_ref, store the min value in left subtree. So that we
     have the correct minimum value for this subtree */
  min = *min_ref;
 
  /* The following recursive call does similar (similar to left subtree) 
    task for right subtree */
  *min_ref =  INT_MAX;
  rs = largestBSTRe(node->right, min_ref, max_ref, max_size_ref, is_bst_ref);
  if (*is_bst_ref == 1 && node->data < *min_ref)
     right_flag = true;
 
  // Update min and max values for the parent recursive calls
  if (min < *min_ref)
     *min_ref = min;
  if (node->data < *min_ref) // For leaf nodes
     *min_ref = node->data;
  if (node->data > *max_ref)
     *max_ref = node->data;
 
  /* If both left and right subtrees are BST. And left and right
     subtree properties hold for this node, then this tree is BST.
     So return the size of this tree */
  if(left_flag && right_flag)
  {
     if (ls + rs + 1 > *max_size_ref)
         *max_size_ref = ls + rs + 1;
     return ls + rs + 1;
  }
  else
  {
    //Since this subtree is not BST, set is_bst flag for parent calls
     *is_bst_ref = 0; 
     return 0;
  }
}
int largestBst(Node *node)
{
    int min=INT_MIN;
    int max=INT_MAX;
    int max_size=0;
    bool is_bst=0;
    largestBSTRe(node,&min,&max,&max_size,&is_bst);
    return max_size;
   
}
