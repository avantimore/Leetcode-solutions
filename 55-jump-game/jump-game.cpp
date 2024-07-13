class Solution {
public:
    bool canJump(vector<int>& nums) {
        int l = 0,r = 0,n = nums.size();
        if(n==1) return 1;
        while(r<n){
            if(nums[l]+l>r){
                r = nums[l]+l;
            }
            if(r==n-1)return 1;
            l++;
            if(l>r)return 0;
        }
        return 1;
    }
};