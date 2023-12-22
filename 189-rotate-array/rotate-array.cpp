class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       
        int n = nums.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int ind = (i+k)%n;
            ans[ind] = nums[i];
        }
        nums=ans;
    }
};