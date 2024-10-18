class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int size = nums.size();

        vector<int> ans(size,0); //we will store our answer in this array
        int posIndex = 0; //all the positive numbers will be at even index
        int negIndex = 1; //all the negative numbers will be at odd index

        for(int i=0; i<nums.size(); i++){

             if(nums[i] < 0){
                 ans[negIndex] = nums[i];
                 negIndex+=2; //increment the index by 2
             }

             else{
                 ans[posIndex] = nums[i];
                 posIndex+=2;
             }

        }

        return ans; //simply return the answer
    }
};