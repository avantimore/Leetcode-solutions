class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==1) return ;
        vector<int> temp;

        k = k%n;

        int i = n-k;
        while(i<n){
            temp.push_back(nums[i]);
            i++;
        }
        i=n-k-1;
        while(i>=0){
            nums[i+k] = nums[i];
            i--;
        }
        i = 0;
        while(i<k){
            nums[i] = temp[i];
            i++;
        }
    }
};