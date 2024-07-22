class Solution {
public:
        void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& visited, int drow[], int dcol[]) {
        visited[r][c] = 1;

        for (int i = 0; i < 4; i++) {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];

            if (nrow >= 0 && nrow < grid.size() && ncol >= 0 && ncol < grid[0].size() && !visited[nrow][ncol] && grid[nrow][ncol] == 1) {
                dfs(nrow, ncol, grid, visited, drow, dcol);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int drow[] = {0, 1, 0, -1};
        int dcol[] = {-1, 0, +1, 0};

        vector<vector<int>> visited(n, vector<int>(m, 0));

        // Check the first and last row
        for (int i = 0; i < m; i++) {
            if (!visited[0][i] && grid[0][i] == 1) {
                dfs(0, i, grid, visited, drow, dcol);
            }
            if (!visited[n-1][i] && grid[n-1][i] == 1) {
                dfs(n-1, i, grid, visited, drow, dcol);
            }
        }

        // Check the first and last column
        for (int i = 0; i < n; i++) {
            if (!visited[i][0] && grid[i][0] == 1) {
                dfs(i, 0, grid, visited, drow, dcol);
            }
            if (!visited[i][m-1] && grid[i][m-1] == 1) {
                dfs(i, m-1, grid, visited, drow, dcol);
            }
        }

        int cnt = 0;
        int bCnt = 0;

        // Count the total land cells and the boundary-connected land cells
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) cnt++;
                if (grid[i][j] == 1 && visited[i][j] == 1) bCnt++;
            }
        }

        int ans = cnt - bCnt;
        return ans;
    }
};