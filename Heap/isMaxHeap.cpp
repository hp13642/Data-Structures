//Given a binary tree check either it is max heap or not
//In order to follow heap property we need to check two things-
  //1-Tree in complete binary tree
  //2-Every node of tree follow max heap property
  
  
  /* This function counts the number of nodes in a binary tree */
unsigned int countNodes(struct Node* root)
{
    if (root == NULL)
        return (0);
    return (1 + countNodes(root->left) + countNodes(root->right));
}
 
/* This function checks if the binary tree is complete or not */
bool isComplete (struct Node* root, unsigned int index,
                 unsigned int number_nodes)
{
    // An empty tree is complete
    if (root == NULL)
        return (true);
 
    // If index assigned to current node is more than
    // number of nodes in tree, then tree is not complete
    if (index >= number_nodes)
        return (false);
 
    // Recur for left and right subtrees
    return (isComplete(root->left, 2*index + 1, number_nodes) &&
            isComplete(root->right, 2*index + 2, number_nodes));
}
bool hasHeapProp(Node* root){
    if(!root)
        return true;
    if(root->left!=NULL && root->right!=NULL){
        if(root->data >root->left->data && root->data > root->right->data)
            return hasHeapProp(root->left) && hasHeapProp(root->right);
        else
            return false;
    }
    else if(root->left){
        if(root->data >root->left->data)
            return hasHeapProp(root->left);
        else
            return false;
    }
    else if(root->right){
        if(root->data > root->right->data)
            return hasHeapProp(root->right);
        else
            return false;
    }
    else
    return true;
}
/*You are required to complete this method */
bool isHeap(Node * tree)
{
    unsigned int size=countNodes(tree);
    bool iscbt=isComplete(tree,0,size);
    if(!iscbt)
        return false;
    bool hasHeap=hasHeapProp(tree);
    if(hasHeap)
        return true;
    else
        return false;
}
