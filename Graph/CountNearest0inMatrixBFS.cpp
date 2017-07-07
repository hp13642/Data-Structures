/*
Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.
Example 1: 
Input:
0 0 0
0 1 0
1 1 1
Output:
0 0 0
0 1 0
1 2 1
*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> res(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0)
                    res[i][j]=0;
                else{
                    queue<pair<int,int>> Q;
                    Q.push({i,j});
                    int c,distance=0;
                    bool flag=true;
                    while(flag){
                        c=Q.size();
                        while(c--){
                            int k=Q.front().first;
                            int l=Q.front().second;
                            Q.pop();
                            if(matrix[k][l]==0){
                                res[i][j]=distance;
                                flag=false;
                                break;
                            }
                            if(k+1<n)
                                Q.push({k+1,l});
                            if(k-1>=0)
                                Q.push({k-1,l});
                            if(l+1<m)
                                Q.push({k,l+1});
                            if(l-1>=0)
                                Q.push({k,l-1});                            
                        }
                        distance++;
                    }
                }
            }
        }
        return res;
    }
};
