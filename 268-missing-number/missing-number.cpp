class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int idealSum = n*(n+1)/2;   

        int sum = 0;
        for(int &i:nums){
            sum += i;
        }
        return (idealSum-sum);
    }
};