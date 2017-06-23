//Finding minimum and maximum value of a node in a given tree

// Returns maximum value in a given Binary Tree
int findMax(struct node* root)
{
    if(!root)
        return -1;
    int max=INT_MIN;
    if(max<root->data)
        max=root->data;
    int l=findMax(root->left);
    int r=findMax(root->right);
    if(l!=-1 && max<l)
        max=l;
    if(r!=-1 && max<r)
        max=r;
    return max;
        
}

// Returns minimum value in a given Binary Tree
int findMin(struct node* root)
{
    if(!root)
        return -1;
    int min=INT_MAX;
    if(min>root->data)
        min=root->data;
    int l=findMin(root->left);
    int r=findMin(root->right);
    if(l!=-1 && min>l)
        min=l;
    if(r!=-1 && min>r)
        min=r;
    return min;
}
