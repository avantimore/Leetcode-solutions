class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        ans.push_back({1});
        if(n==1)return ans;
        ans.push_back({1,1});
        for(int i=2;i<n;i++){
            vector<int> temp;
            temp.push_back(1);
            int sz = ans.size();
            for(int j=0;j<ans[sz-1].size()-1;j++){
                int sum = ans[sz-1][j]+ans[sz-1][j+1];
                temp.push_back(sum);
            }
            temp.push_back(1);
            ans.push_back(temp);
        }
        return ans;
    }
};