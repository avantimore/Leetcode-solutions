class Solution {
public:
    int find(int node,vector<int> &rank,vector<int> &parent) {
        if (node == parent[node])
            return node;
        return parent[node] = find(parent[node],rank,parent);
    }
    void unionByRank(int u, int v,vector<int> &rank,vector<int> &parent) {
        int ulp_u = find(u,rank,parent);
        int ulp_v = find(v,rank,parent);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    int makeConnected(int v, vector<vector<int>>& connections) {
        vector<int> rank(v,0),parent(v);
        for (int i = 0; i < v; i++) {
            parent[i] = i;
        }
        int e = connections.size();
        if(v-1>e)return -1;

        int cnt = 0;
        for(int i=0;i<e;i++){
            int u = connections[i][0];
            int v = connections[i][1];

            if (find(u,rank,parent) != find(v,rank,parent)) {
                cnt++;
                unionByRank(u, v,rank,parent);
            }
        }
        return v - 1 - cnt;
    }
};