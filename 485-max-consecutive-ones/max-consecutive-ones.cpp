class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int maxCnt=0;

        for(int i=0;i<n;i++){
            if(nums[i]==1)cnt++;
            else{
                maxCnt = max(maxCnt,cnt);
                cnt = 0;
            }
        }
        return max(maxCnt,cnt);
    }
};