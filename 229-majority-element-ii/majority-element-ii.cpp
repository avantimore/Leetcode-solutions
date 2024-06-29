class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int bound = floor(n/3);

        vector<int> ans;

        int count=0;
        int i=0;
        for(;i<n-1;i++){
            
            ++count;

            if(nums[i]!=nums[i+1]){
                if(count>bound) ans.push_back(nums[i]);
                count=0;
            }
        }
        if(i==n-1){
            ++count;
            if(count>bound) ans.push_back(nums[i]);
        }

        return ans;
    }
};