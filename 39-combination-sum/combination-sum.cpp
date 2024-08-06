class Solution {
public:

    void solve(vector<int>& nums,vector<int> temp,vector<vector<int>> &ans,int i,int sum,int target){
        
        if(i>=nums.size() || sum>target)return;
        if(sum==target){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        solve(nums,temp,ans,i,sum+nums[i],target);
        temp.pop_back();
        solve(nums,temp,ans,i+1,sum,target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        int sum= 0;

        solve(nums,temp,ans,0,sum,target);
        return ans;
    }
};