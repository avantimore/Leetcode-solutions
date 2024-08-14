class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> indg(n,0);
        vector<vector<int>> adj(n);
        for(int i=0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
            indg[u]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indg[i]==0) q.push(i);
        }

        int cnt =0;
        while(!q.empty()){
            int i = q.front();
            q.pop();
            cnt++;

            for(int it:adj[i]){
                indg[it]--;
                if(indg[it]==0) q.push(it);
            }
        }
        if(cnt==n)return true;
        return false;
    }
};