class Solution {
public:
    void reverse(int i, int j, vector<int>& nums) {
        while (i < j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }

    void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;  // Ensure k is within the range of array size
    reverse(0, n - 1, nums);  // Reverse the entire array
    reverse(0, k - 1, nums);  // Reverse the first part up to k
    reverse(k, n - 1, nums);  // Reverse the second part from k to end
}
};