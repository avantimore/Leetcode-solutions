class Solution {
public:
    // Simple dfs -> for path printing.
    
    void solve(int node , vector<int> &temp , vector<vector<int>> &ans , vector<int> &visited , vector<int> adj[] , int n)
    {
        visited[node] = 1;
        temp.push_back(node);

        if(node == n-1)
        {
            ans.push_back(temp);
            return ;
        }

        for(auto neigh : adj[node])
        {
            if(visited[neigh] == 0)
            {
                solve(neigh , temp , ans , visited , adj , n);
                visited[neigh] = 0;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;

        int n = graph.size();

        vector<int> adj[n];

        for(int i = 0 ; i < n ; i++)
        {
            int u = i;
            for(auto v : graph[i])
            {
                adj[u].push_back(v);
            }
        }

        vector<int> temp;

        vector<int> visited(n , 0);
        
        solve(0 , temp , ans , visited , adj , n);

        return ans;
    }
};