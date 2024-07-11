class Solution {
public:
    void solve(vector<vector<int>>& ans,vector<int> &temp,vector<int>& nums,int i,int n){
        
        if(i>=n){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        solve(ans,temp,nums,i+1,n);
        temp.pop_back();
        solve(ans,temp,nums,i+1,n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();
        solve(ans,temp,nums,0,n);
        return ans;
    }
};