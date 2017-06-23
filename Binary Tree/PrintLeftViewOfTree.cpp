//Printing Left view of a given Binary Tree

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// A wrapper over leftViewUtil()
void leftView(Node *root)
{
    if(!root)
        return;
    queue<Node *> Q;
    Q.push(root);
    int count=0;
    while(!Q.empty()){
        count=Q.size();
        bool first=true;
        while(count--){
            Node *temp=Q.front();
            Q.pop();
            if(first){
                cout<<temp->data<<" ";
                first=false;
            }
            if(temp->left)
                Q.push(temp->left);
            if(temp->right)
                Q.push(temp->right);
        }
    }
}
