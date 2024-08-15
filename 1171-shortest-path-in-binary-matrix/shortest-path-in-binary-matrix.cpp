class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1)return -1;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans(n,vector<int>(m,1e9));
        ans[0][0] = 0;

        queue<pair<int,pair<int,int>>>q;
        q.push({0,{0,0}});

        int drow[] = {-1,-1,-1,0,1,1,1,0};
        int dcol[] = {-1,0,1,1,1,0,-1,-1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second.first;
            int d = q.front().second.second;
            q.pop();
            if(r==n-1 && c==m-1)return d+1;

            for(int i=0;i<8;i++){
                int nrow = drow[i]+r;
                int ncol = dcol[i]+c;

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==0 && ans[nrow][ncol]>d+1){
                    ans[nrow][ncol] = d+1;
                    q.push({nrow,{ncol,d+1}});
                }
            }
        }

        return -1;
    }
};