class Solution {
public:
    bool solve(int i,vector<int> &arr, int k,vector<vector<int>> &dp){
        if(k==0) return 1;
        if(i==0) return arr[0]==k;
        
        if(dp[i][k]!=-1) return dp[i][k];
        int notTake = solve(i-1,arr,k,dp);
        int take = 0;
        if(arr[i]<=k) take = solve(i-1,arr,k-arr[i],dp);
        
        return dp[i][k] = (take || notTake);
    }
    bool isSubsetSum(vector<int> &arr, int sum){
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int> (sum+1,-1));
        return solve(n-1,arr,sum,dp);
    }
    bool canPartition(vector<int>& arr) {
        int totSum = 0;
        int n = arr.size();
        for(int &i:arr){
            totSum += i;
        }
        if(totSum%2) return 0;
        int sum = totSum/2;
        return isSubsetSum(arr,sum);
    }
};