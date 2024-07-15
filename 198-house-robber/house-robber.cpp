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

        int prev1 = nums[0];
        int prev2 = 0;
        
        for(int i=1;i<n;i++){
            int take = nums[i] + prev2;
            int notTake = prev1;
            int maxi = max(take,notTake);

            prev2 = prev1;
            prev1 = maxi;
        }

        return prev1;
    }
};