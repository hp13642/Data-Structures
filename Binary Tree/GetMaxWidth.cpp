//Getting maximum width of a binary tree
//Where width is maximum number of node at any level

/*  Structure of a Binary Tree 
struct Node
{
    int data;
    Node* left, *right;
}; */

/* Function to get the maximum width of a binary tree*/
int getMaxWidth(Node* root)
{
    if(!root)
        return 0;
    queue<Node *> Q;
    Q.push(root);
    int max=0;
    int count;
    while(!Q.empty()){
        count=Q.size();
        if(count>max)
            max=count;
        while(count--){
            Node *temp=Q.front();
            Q.pop();
            if(temp->left)
                Q.push(temp->left);
            if(temp->right)
                Q.push(temp->right);
        }
    }
    return max;
}
