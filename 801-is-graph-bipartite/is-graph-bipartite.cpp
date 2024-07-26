class Solution {
public:
    bool bfs(vector<vector<int>>& adj, vector<pair<int, int>>& visited, int src) {
        queue<int> q;
        q.push(src);
        visited[src] = {1, 0};
        
        while (!q.empty()) {
            int qfront = q.front();
            q.pop();
            int currentFlag = visited[qfront].second;
            
            for (int &i : adj[qfront]) {
                if (!visited[i].first) {
                    q.push(i);
                    visited[i] = {1, 1 - currentFlag};
                } else {
                    if (visited[i].second == currentFlag) return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<pair<int, int>> visited(V, {0, 0});
        
        for (int i = 0; i < V; i++) {
            if (!visited[i].first) {
                if (!bfs(graph, visited, i)) return false;
            }
        }
        return true;
    }
    
};