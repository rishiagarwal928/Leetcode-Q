class Solution {
public:
    int mp(vector<vector<int>> &dp,int i,int j,vector<vector<int>> &grid) {
        if(i==0 and j==0) return grid[i][j];
        if(i<0 or j<0) return 1e9;    
        if(dp[i][j]!=-1) return dp[i][j];
        int up = grid[i][j] + mp(dp,i-1,j,grid);
        int left = grid[i][j] + mp(dp,i,j-1,grid);
        return dp[i][j] = min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n+1,-1));
        return mp(dp,m-1,n-1,grid);
    }
};