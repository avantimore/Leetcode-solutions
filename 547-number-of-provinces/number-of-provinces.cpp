class Solution {
public:
    void dfs(vector<vector<int>>& adj,vector<int> &visited,int N,int src){
            visited[src] = 1;
            
            for(int &i:adj[src]){
                if(!visited[i]){
                    dfs(adj,visited,N,i);
                }
            }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        int ans = 0;
        vector<int> visited(V,0);
        
        vector<vector<int>> adj(V);
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(isConnected[i][j]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        for(int i=0;i<V;i++){
            
            if(!visited[i]){
                dfs(adj,visited,V,i);
                ans++;
            }

        }
        return ans;
    }
};