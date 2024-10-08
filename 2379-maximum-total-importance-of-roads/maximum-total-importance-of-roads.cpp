class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
       vector<long long> degree(n,0);
        int r = roads.size();

       for(int i=0;i<r;i++){
            degree[roads[i][0]]++;
            degree[roads[i][1]]++;
       }
       sort(degree.begin(),degree.end());
       long long res = 0;

       for(int i=0;i<n;i++){
         res += degree[i] * (i+1);
       }

       return res;
    }
};