//In a given binary tree printing ancestors of a given node if ancestors found then print and return true
//else return false

/*
Structure of a node is as following
struct Node
{
     int data;
     struct Node* left;
     struct Node* right;
};
*/
// Function should print all the ancestor of the target node
bool Ancestors(struct Node *root,int target){
    
    if(root==NULL)
        false;
    if(root->data==target){
        //cout<<root->data;
        return true;
    }
    if((root->left!=NULL && Ancestors(root->left,target)) || 
        (root->right!=NULL && Ancestors(root->right,target))){
        cout<<root->data<<" ";
        return true;
    }
    return false;
}
//Function to print newline character at the end of each test cases
bool printAncestors(struct Node *root, int target)
{
    if(!root)
        return false;
    bool flag=Ancestors(root,target);
    if(flag)
        cout<<endl;
    return flag;
}
