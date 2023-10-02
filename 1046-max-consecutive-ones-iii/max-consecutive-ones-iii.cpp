class Solution {
public:
    // int longestOnes(vector<int>& nums, int k) {
    //     int countZeros=k;
    //     int n = nums.size();
    //     int maxi = 0;
    //     int cnt = 0;
    //     for(int i=0;i<n;i++){
    //         if(nums[i]==1){
    //             cnt++;
    //             maxi = max(maxi,cnt);
    //         }
    //         else if(nums[i]==0 && k!=0){
    //             cnt++;
    //             maxi = max(maxi,cnt);
    //             countZeros--;
    //         }
    //         else{
    //             cnt=0;
    //             countZeros=k;
    //         }
    //     }
    //     return maxi;
    // }

    int longestOnes(vector<int>& nums, int k) {
    int n = nums.size();
    int left = 0, right = 0;
    int maxOnes = 0;
    int zeroCount = 0;

    while (right < n) {
        if (nums[right] == 0) {
            zeroCount++;
        }

        while (zeroCount > k) {
            if (nums[left] == 0) {
                zeroCount--;
            }
            left++;
        }

        maxOnes = max(maxOnes, right - left + 1);
        right++;
    }

    return maxOnes;
}

    
};