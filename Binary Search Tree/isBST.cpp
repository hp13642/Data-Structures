//Given a BST ,testing either the given tree is a bst or not
//here key are assumes unique ie valur of each node is different otherwise we have to make some minor changes

/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node {
    int data;
    Node* left, * right;
}; */
/* Should return true if tree represented by root is BST. 
   For example, return  value should be 1 for following tree.
         20
     /      \ 
   10       30
  and return value should be 0 for following tree.
         10
     /      \ 
   20       30 */
bool isBstTest(Node *root,int min,int max){
    if(!root)
        return true;
    if(root->data<min || root->data>max)
        return false;
    return isBstTest(root->left,min,root->data-1) &&
            isBstTest(root->right,root->data+1,max);
}
bool isBST(Node* root) {
    return isBstTest(root,INT_MIN,INT_MAX);
}
