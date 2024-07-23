class Solution {
public:
    int solve(int n,int m,vector<vector<int>>& grid,vector<vector<int>> &dp){
        if (m < 0 || n < 0) return INT_MAX;
        if (m == 0 && n == 0) return grid[0][0];

        if(dp[n][m]!=-1)return dp[n][m];

        int left = solve(n,m-1,grid,dp);
        int up = solve(n-1,m,grid,dp);

        return dp[n][m] = grid[n][m] + min(left,up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n-1,m-1,grid,dp);
    }
};