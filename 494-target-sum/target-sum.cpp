class Solution {
public:
    int solve(int i,vector<int> &arr, int target){
        // if(target==0) return 1;  ---> he ka nahi kela coz there might still be further goshti which will make diff permutations to makeup the target
        if (i == 0) {
            if (arr[0] == target || arr[0] == -target) {
                return (arr[0] == target) + (arr[0] == -target);
            } else {
                return 0;
            }
        }

        int plus = solve(i - 1, arr, target - arr[i]);
        int minus = solve(i - 1, arr, target + arr[i]);

        return plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return solve(n-1,nums,target);
    }
};