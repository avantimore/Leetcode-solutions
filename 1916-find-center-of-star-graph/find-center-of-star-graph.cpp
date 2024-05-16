class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adjlist;
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adjlist[v].push_back(u);
            adjlist[u].push_back(v);
        }

        int n = adjlist.size();
        for(int i=1;i<=n;i++){
            int sz = adjlist[i].size();
            if(sz==n-1)return i;
        }
        return -1;
    }
};