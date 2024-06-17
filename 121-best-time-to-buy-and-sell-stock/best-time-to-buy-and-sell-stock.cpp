class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int greater = 0;
        int n = prices.size();

        for(int i=n-1;i>=0;i--){
            if(prices[i]<greater){
                prices[i] = greater - prices[i];
            }
            else{
                greater = prices[i];
                prices[i] = 0;
            }
        }

        int maxProf = INT_MIN;
        for(int i=0;i<n;i++){
            maxProf = max(maxProf,prices[i]);
        }
        return maxProf;
    }
};