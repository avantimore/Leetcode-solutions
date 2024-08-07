class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        vector<vector<int>> dist(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    visited[i][j] = 1;
                    q.push({{i,j},0});
                }
            }
        }

        int drow[] = {-1,1,0,0};
        int dcol[] = {0,0,-1,1};

        while(!q.empty()){
            auto qfront = q.front();
            q.pop();
            int r = qfront.first.first;
            int c = qfront.first.second;
            int d = qfront.second;

            dist[r][c] = d;

            for(int i=0;i<4;i++){
                int nrow = drow[i]+r;
                int ncol = dcol[i]+c;

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol]){
                    q.push({{nrow,ncol},d+1});
                    visited[nrow][ncol] = 1;
                }
            }
        }
        return dist;
    }
};