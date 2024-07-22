class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));

        int oldcolor = image[sr][sc];
        queue<pair<int,int>> q;
        q.push({sr,sc});
        visited[sr][sc] = 1;

        int drow[] = {0,1,0,-1};
        int dcol[] = {-1,0,1,0};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            image[r][c] = color;
            
            for(int i=0;i<4;i++){
                int nrow = r+drow[i];
                int ncol = c+dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==oldcolor && !visited[nrow][ncol]){
                    q.push({nrow,ncol});
                    visited[nrow][ncol] = 1;
                }
            }
        }
        return image;
    }
};