class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int zero = 0;
        int n = nums.size();

        while(i<n && j<n){
            if(nums[j]==0){
                j++;
            }
            else{
                nums[i++] = nums[j++];
            }
        }

        while(i<n){
            nums[i++] = 0;
        }
    }
};