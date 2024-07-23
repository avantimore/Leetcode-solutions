class Solution {
public:
    int solve(vector<vector<int>>& grid,int m, int n,vector<vector<int>> &memo) {
        if (m < 0 || n < 0) return 0;
        if(grid[m][n] == 1) return 0;
        if (m == 0 && n == 0) return 1;
        if(memo[m][n]!=-1)return memo[m][n];
        return memo[m][n] = solve(grid,m - 1, n,memo) + solve(grid,m, n - 1,memo);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> memo(n, vector<int>(m, -1));
        return solve(grid,n-1,m-1,memo);
    }
};