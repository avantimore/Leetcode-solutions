class Solution {
public:
    int solve(vector<vector<int>>& grid,int r,int c,int n,vector<vector<int>> &dp){
        if(r>=n || c>=n || c<0)return INT_MAX;
        if(r==n-1){
            return grid[r][c];
        }
        if(dp[r][c]!=INT_MAX)return dp[r][c];
        int mini = INT_MAX;
        for(int i=-1;i<=1;i++){
            int next = solve(grid, r + 1, c + i, n,dp);
            if (next != INT_MAX) {
                mini = min(mini, grid[r][c] + next);
            }
        }

        return dp[r][c] = mini;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n==1) return matrix[0][0];

        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        int mini = INT_MAX;
        for(int i=0;i<n;i++){
            mini = min(mini,solve(matrix,0,i,n,dp));
        }
        return mini;
    }
};