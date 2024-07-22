class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n =grid.size();
        int m = grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));

        queue<pair<int,pair<int,int>>> q;
        int maxTime = 0;
        int freshCnt = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({0,{i,j}});
                    visited[i][j] = 1;
                }
                else if(grid[i][j] == 1){
                    freshCnt++;
                }
            }
        }

        int drow[] = {0,1,0,-1};
        int dcol[] = {-1,0,1,0};
        int cnt = 0;

        while(!q.empty()){
            int time = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();

            maxTime = max(maxTime,time);
            
            for(int i=0;i<4;i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && visited[nrow][ncol]==0){
                    q.push({time+1,{nrow,ncol}});
                    visited[nrow][ncol] = 1;
                    cnt++;
                }
            }
        }
        if(cnt!=freshCnt)return -1;

        return maxTime;
    }
};