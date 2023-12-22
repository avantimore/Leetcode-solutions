class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int ans=-1;
        vector<int> mark(n+1);

        for(int i=0;i<n;i++){
            int ind = nums[i];
            mark[ind]=INT_MIN;
        }
        for(int i=0;i<n;i++){
            if(mark[i]!=INT_MIN){
                ans = i;
            }
        }
        if(ans == -1){
            return n;
        }
        return ans;
    }
};