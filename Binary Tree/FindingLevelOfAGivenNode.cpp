//Find level of a given node in binary tree assume root is at level 1
//If Node is not foun in tree then return -1

/*
Structure of the node of the binary tree is
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
*/
// function should return level of the target node
int getLevel(struct Node *root, int target)
{
    if(!root)
        return -1;
    queue<Node *> Q;
    Q.push(root);
    int level=0;
    int count;
    while(!Q.empty()){
        count=Q.size();
        level++;
        while(count--){
            Node *temp=Q.front();
            if(temp->data==target)
                return level;
            Q.pop();
            if(temp->left)
                Q.push(temp->left);
            if(temp->right)
                Q.push(temp->right);
        }
    }
	return -1;
}
