 #include<algorithm>
class Solution {
   
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxAvg = INT_MIN;
        double currSum = 0;
        int n = nums.size();
        for(int i=0;i<k;i++){
            currSum += nums[i];
        }
        
        if(maxAvg > currSum/k){
            maxAvg = maxAvg;
        }
        else{
            maxAvg = currSum/k;
        }
        for(int i=1;i<=n-k;i++){
            currSum = currSum - nums[i-1] + nums[i+k-1];
            if(maxAvg > currSum/k){
                maxAvg = maxAvg;
            }
            else{
                maxAvg = currSum/k;
            }
        }
        return maxAvg;
    }
};