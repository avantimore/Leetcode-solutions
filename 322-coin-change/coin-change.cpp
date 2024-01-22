class Solution {
public:
    
    int coinChangeHelper(vector<int> &dp,int n,vector<int> coins){
        if(n==0)return 0;

        int ans=INT_MAX;

        for(int i=0;i<coins.size();i++){
            if(n-coins[i]>=0){
                int subAns=0;
                if(dp[n-coins[i]]!=-1){
                    subAns = dp[n-coins[i]];
                }
                else{
                    subAns = coinChangeHelper(dp,n-coins[i],coins);
                }
                if(subAns!=INT_MAX && subAns+1<ans){
                    ans = subAns+1;
                }
            }   
        }
        return dp[n] = ans;
    } 
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        dp[0] = 0;
        int ans = coinChangeHelper(dp, amount, coins);
        if(ans==INT_MAX)return -1; 
        return ans;
    }
};