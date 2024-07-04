class Solution {
public:
    void solve(std::vector<int>& nums, std::vector<std::vector<int>>& ans, std::vector<int>& temp, int start) {
        // Add current subset to the answer
        ans.push_back(temp);
        
        for (int i = start; i < nums.size(); i++) {
            // Skip duplicates
            if (i > start && nums[i] == nums[i - 1]) continue;
            
            temp.push_back(nums[i]);
            solve(nums, ans, temp, i + 1); // Move to the next element
            temp.pop_back(); // Backtrack
        }
    }

   vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::vector<std::vector<int>> ans;
        std::vector<int> temp;
        std::sort(nums.begin(), nums.end()); // Sort to handle duplicates
        solve(nums, ans, temp, 0);
        return ans;
    }
};