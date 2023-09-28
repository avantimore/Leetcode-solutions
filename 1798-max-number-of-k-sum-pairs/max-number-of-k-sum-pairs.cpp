class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int count=0;
        int i=0;
        int j=nums.size()-1;

        while(i<j){
            if(nums[i]+nums[j]==k){
                i++;
                j--;
                count++;
            }
            else if(nums[i]+nums[j]<k){
                i++;
            }
            else if(nums[i]+nums[j]>k){
                j--;
            }
        }
        return count;
    }
};