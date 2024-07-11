class Solution {
public:
    void solve(vector<vector<int>>& ans,vector<int> &temp,vector<int>& nums,int i,int n){
        ans.push_back(temp);
        // if(i>=n)return;
        for(int j=i;j<n;j++){
            temp.push_back(nums[j]);
            solve(ans,temp,nums,j+1,n);
            temp.pop_back();
        }
        // solve(ans,temp,nums,i+1,n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();
        solve(ans,temp,nums,0,n);
        return ans;
    }
};