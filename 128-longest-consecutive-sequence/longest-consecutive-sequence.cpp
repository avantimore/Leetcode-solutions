class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        // Remove duplicates and sort
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        
        int count = 1, maxCount = 1;
        int n = nums.size();
        
        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                // Continue the sequence
                count++;
            } else {
                // Sequence breaks, update maxCount and reset count
                maxCount = max(maxCount, count);
                count = 1; // Reset count for the next sequence
            }
        }
        
        // Final update for the last sequence
        maxCount = max(maxCount, count);
        
        return maxCount;
    }
};
