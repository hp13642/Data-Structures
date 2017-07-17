/*
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]
*/

class Solution {
public:
    void hasPathSum(TreeNode* root,vector<string> &paths,string &s,bool start) {
        if(!root)
            return;
        if(!start)
            s+="->";
        s+=to_string(root->val);
        if(root->left==NULL && root->right==NULL){
            paths.push_back(s);
            return;
        }
        else if(root->left==NULL){
            hasPathSum(root->right,paths,s,false);
            s.pop_back();
            while(s.back()!='>')
                  s.pop_back();
            s.pop_back();
            s.pop_back();
        }
        else if(root->right==NULL){
            hasPathSum(root->left,paths,s,false);
            s.pop_back();
            while(s.back()!='>')
                  s.pop_back();
            s.pop_back();
            s.pop_back();
        }
        else{
            hasPathSum(root->left,paths,s,false);
            s.pop_back();
            while(s.back()!='>')
                  s.pop_back();
            s.pop_back();
            s.pop_back();
            hasPathSum(root->right,paths,s,false);
            s.pop_back();
           while(s.back()!='>')
                  s.pop_back();
            s.pop_back();
            s.pop_back();
        }
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>paths;
        string s;
        if(!root)
            return paths;
        bool start=true;
        hasPathSum(root,paths,s,start);
        return paths;
    }
};
