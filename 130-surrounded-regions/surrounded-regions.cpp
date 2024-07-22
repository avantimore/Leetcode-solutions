class Solution {
public:
    void dfs(int r,int c,vector<vector<char>>& grid,vector<vector<int>> &visited,int drow[],int dcol[]){
        visited[r][c] = 1;

        for(int i=0;i<4;i++){
            int nrow = r+drow[i];
            int ncol = c+dcol[i];

            if(nrow<grid.size() && nrow>=0 && ncol<grid[0].size() && ncol>=0 && !visited[nrow][ncol] && grid[nrow][ncol]=='O'){
                dfs(nrow,ncol,grid,visited,drow,dcol);
            }
        }
    }
    void solve(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int> (m,0));

        int drow[] = {0,1,0,-1};
        int dcol[] = {-1,0,1,0};

        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 'O' && !visited[i][0]) {
                dfs(i, 0, grid, visited, drow, dcol);
            }
            if (grid[i][m - 1] == 'O' && !visited[i][m - 1]) {
                dfs(i, m - 1, grid, visited, drow, dcol);
            }
        }
        for (int i = 0; i < m; i++) {
            if (grid[0][i] == 'O' && !visited[0][i]) {
                dfs(0, i, grid, visited, drow, dcol);
            }
            if (grid[n - 1][i] == 'O' && !visited[n - 1][i]) {
                dfs(n - 1, i, grid, visited, drow, dcol);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]=='O'){
                    grid[i][j]='X';
                }
            }
        }
        return ;
    }
};