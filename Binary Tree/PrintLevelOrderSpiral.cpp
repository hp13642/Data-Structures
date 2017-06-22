//Printing a given binary tree in level order manner as well as spiral order

/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */


void printSpiral(Node *root)
{
    deque<Node *> Q;
    Q.push_back(root);
    int c=0,count;
    bool leftFlag=false;
    while(!Q.empty()){
        count=Q.size();
        while(count--){
            Node *temp;
            if(leftFlag){
                temp=Q.front();
                Q.pop_front();
            }
            else{
                temp=Q.back();
                Q.pop_back();
            }
            cout<<temp->data<<" ";
            if(temp->left)
                Q.push_back(temp->left);
            if(temp->right)
                Q.push_back(temp->right);
        }
        leftFlag=!leftFlag;
    }
}
