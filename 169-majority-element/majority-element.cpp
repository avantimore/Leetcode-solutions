class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();

        int count=0;
        int i=0;
        for(;i<n-1;i++){
            
            ++count;
            if(count>n/2)return nums[i];

            if(nums[i]!=nums[i+1]){
                count=0;
            }
        }
        if(i==n-1){
            ++count;
            if(count>n/2)return nums[i];
        }

        return 0;
    }
};