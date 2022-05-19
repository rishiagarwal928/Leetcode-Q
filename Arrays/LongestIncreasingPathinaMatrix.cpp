class Solution {
public:
    bool isvalid(int i,int j,int m,int n) {
        return (i>=0 and i<m and j>=0 and j<n);
    }
    int dfs(int i,int j,vector<vector<int>> &grid,vector<vector<int>>& matrix,int m,int n) {
        if(grid[i][j]!=0) return grid[i][j];
        vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        int c = 1;
        for(auto x:dir){
            int ni = i+x[0];
            int nj = j+x[1];
            if(isvalid(ni,nj,m,n) and matrix[ni][nj]>matrix[i][j]) {
                c = max(c,1+dfs(ni,nj,grid,matrix,m,n));
            }
        }
        return grid[i][j] = c;
        
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        vector<vector<int>> grid(m,vector<int>(n,0));
        for(int i=0;i<m;++i){
            for(int j = 0;j<n;++j){
                ans = max(ans,dfs(i,j,grid,matrix,m,n));
            }
        }
        return ans;
    }
};
