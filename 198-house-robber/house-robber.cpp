class Solution {
public:
    int solve(int i,vector<int>& nums,vector<int> &dp){
        if(i==0){
            return dp[0] = nums[0];
        }
        if(i<0)return 0;

        if(dp[i]!=-1) return dp[i];
        int take = nums[i] + solve(i-2,nums,dp);
        int notTake = solve(i-1,nums,dp);

        return dp[i] = max(take,notTake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        // if(n==1)return nums[0];
        // if(n==2) return max(nums[0],nums[1]);
        
        // for(int i=2;i<n;i++){

        // }


        vector<int> dp(n,-1);
        return solve(n-1,nums,dp);
    }
};