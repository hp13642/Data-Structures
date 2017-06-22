//Print all nodes of given binary tree which are k distance apart from root node

/* A binary tree node has data, pointer to left child
   and a pointer to right child /
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

// Recursive function to print right view of a binary tree.
void printKdistance(Node *root, int k)
{
    if(!root)
        return;
    queue<Node *> Q;
    Q.push(root);
    int level=0;
    int count;
    while(!Q.empty()){
        count=Q.size();
        level++;
        while(count--){
            Node *temp=Q.front();
            if(level==k+1)
                cout<<temp->data<<" ";
            Q.pop();
            if(temp->left)
                Q.push(temp->left);
            if(temp->right)
                Q.push(temp->right);
        }
        if(level>k+1)
            return;
    }
}
