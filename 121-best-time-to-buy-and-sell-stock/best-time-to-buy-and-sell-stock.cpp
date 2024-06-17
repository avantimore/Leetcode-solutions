class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int greater = 0;
        int n = prices.size();
        int maxProf = 0;

        for(int i=n-1;i>=0;i--){
            if(prices[i]<greater){
                maxProf = max(maxProf,greater - prices[i]);
            }
            else{
                greater = prices[i];
                prices[i] = 0;
            }
        }

        return maxProf;
    }
};