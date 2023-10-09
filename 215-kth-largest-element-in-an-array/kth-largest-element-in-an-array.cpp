
#include <queue> 
class Solution {
    
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        int n = nums.size();
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
        }
        int ans = -1;
        for(int i=0;i<k;i++){
            ans = pq.top();
            pq.pop();
        }
        return ans;
    }
};