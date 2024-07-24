class Solution {
public:
    int solve(int i,vector<int>& arr,int amt,vector<vector<int>> &dp){
        if(i==0){
            if(amt % arr[0]==0)return 1;
            else return 0;
        }
        if(dp[i][amt] != -1)return dp[i][amt];
        int take = 0;
        if(amt>=arr[i]) take = solve(i,arr,amt-arr[i],dp);
        int nottake = solve(i-1,arr,amt,dp);

        return dp[i][amt] = (take + nottake);
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return solve(n-1,coins,amount,dp);
    }
};