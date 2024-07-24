class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxi = INT_MIN;
        int mini = prices[0];
        for(int i=1;i<n;i++){
            if(prices[i]-mini>0){
                maxi = max(maxi,prices[i]-mini);
            }
            else{
                mini = prices[i];
            }
        }
        return (maxi!=INT_MIN)?maxi:0;
    }
};