/* A binary tree Node
Node
{
    int data;
    Node* left, * right;
}; */


void levelOrder(Node* node)
{
    if(!node)
        return;
    queue<Node *> Q;
    Q.push(node);
    while(!Q.empty()){
        Node *temp=Q.front();
        Q.pop();
        cout<<temp->data<<" ";
        if(temp->left)
            Q.push(temp->left);
        if(temp->right)
            Q.push(temp->right);
    }
}


