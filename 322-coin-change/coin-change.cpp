class Solution {
public:
    int solve(int i,vector<int>& coins, int amt,vector<vector<int>> &dp){

        if(i<=0){
            if(amt%coins[0]==0)return (amt/coins[0]);
            else return 1e9;
        }
        if(dp[i][amt]!=-1)return dp[i][amt];
        int nottake = solve(i-1,coins,amt,dp);
        int take = 1e9;
        if(amt>=coins[i]) take = 1+solve(i,coins,amt-coins[i],dp);

        return dp[i][amt] = min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        if(amount==0)return 0;

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = solve(n-1,coins,amount,dp);
        return (ans==1e9)? -1:ans;
    }
};