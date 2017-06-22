//In a given Binary Tree Mirror Node of given Node where 1 is rot node and mirror image is taken with respect to root node i.e 1

#include <bits/stdc++.h>
using namespace std;
struct Node{
    int left;
    int right;
    Node(){
        left=right=-1;
    }
};
int FindMirrorNodeRec(int given,vector<Node> &Tree, int left, int right)
{
    // if either node is NULL then there is no mirror node
    if (left ==-1 || right ==-1)
        return -1;
    // check the current candidates
    if (given ==left)
        return right;
    if (given == right)
        return left;
    // try recursively
    // (first external then internal nodes)
    int res = FindMirrorNodeRec(given,Tree, Tree[left].left, Tree[right].right);
    if (res != -1)
        return res;
    return FindMirrorNodeRec(given,Tree,Tree[left].right, Tree[right].left);
}

int FindMirrorNodeData(vector<Node> &Tree,int given)
{
    if (Tree.size()<2)
        return -1;
    if (given ==1)
        return 1;
    // call the search function
    return FindMirrorNodeRec(given,Tree,Tree[1].left,Tree[1].right );
}
int main()
{
    int N,Q;
    cin>>N>>Q;
    vector<Node> Tree(N+1);
    vector<Node> mirrorTree(N+1);
    for(int i=1;i<N;i++){
        int x,y;
        char type;
        cin>>x>>y>>type;
        if(type=='L'){
            Tree[x].left=y;
            mirrorTree[x].right=y;
        }
        else{
            Tree[x].right=y;
            mirrorTree[x].left=y;
        }
    }
    while(Q--){
        int r;
        cin>>r;
        int result=FindMirrorNodeData(Tree,r);
        cout<<result<<endl;
    }
    return 0;
}
