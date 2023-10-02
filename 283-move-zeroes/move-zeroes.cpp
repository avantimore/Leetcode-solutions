class Solution {
public:
   void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int s = 0;
    int mid = 0;
    int e = n - 1;
    while (mid <= e) {
        if (nums[mid] != 0) {
            swap(nums[mid], nums[s++]);
        }
        mid++;
    }
}

};