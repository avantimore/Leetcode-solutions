
#include<algorithm>
class Solution {
    
public:
    int max(int i,int j){
        if(i<j)return j;
        return i;
    }
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double maxAvg = INT_MIN;
        double currSum = 0;
        for(int i=0;i<k;i++){
            currSum += nums[i];
        }
        if (maxAvg > currSum / k) {
    maxAvg = maxAvg;
} else {
    maxAvg = currSum / k;
}

        for(int i=1;i<=n-k;i++){
            currSum = currSum - nums[i-1] + nums[i+k-1];
            if (maxAvg > currSum / k) {
    maxAvg = maxAvg;
} else {
    maxAvg = currSum / k;
}

        }
        return maxAvg;
    }
};