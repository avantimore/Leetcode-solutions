class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        long long backSum = 0;
        int n = nums.size();
        for(int i=1;i<n;i++){
            backSum +=nums[i];
        }
        if(backSum==0){
            return 0;
        }
        long long frontSum = nums[0];
        for(int i=1;i<n;i++){
            
            backSum -= nums[i];
            if(backSum==frontSum){
                return i;
            }
            frontSum +=nums[i];
        }
        if(frontSum-nums[n-1]==0){
            return n-1;
        }
        return -1;
    }
};