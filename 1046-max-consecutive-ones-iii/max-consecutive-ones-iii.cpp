class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zero = k;
        int n = nums.size();
        int maxi = 0;
        int l=0,r=0;
        while(r<n){
            if (nums[r] == 1) {
                // Simply move the right pointer forward
                r++;
            } else {
                if (zero > 0) {
                    // Use one of the allowed zeros
                    zero--;
                    r++;
                } else {
                    // Move the left pointer to reduce the window size
                    if (nums[l] == 0) {
                        zero++;
                    }
                    l++;
                }
            }
            
            // Update the maximum length of the subarray
            maxi = max(maxi, r - l);
        }
        return maxi;
    }
};