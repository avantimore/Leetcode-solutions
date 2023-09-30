class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        // sort(nums.begin(),nums.end());
        // int i=0;
        // int j=nums.size()-1;
        // int count=0;

        // while(i<j){
        //     if(nums[i]+nums[j]==k){
        //         count++;
        //         i++;
        //         j--;
        //     }
        //     else if(nums[i]+nums[j]<k){
        //         i++;
        //     }
        //     else{
        //         j--;
        //     }
        // }
        // return count;

        unordered_map<int, int> m;
		int ans = 0;
		for(int i = 0; i < nums.size(); i++){
			if(m[k - nums[i]] > 0){
			   m[k - nums[i]]--;
				ans++;
			}
			else{
				m[nums[i]]++;
			}
		}
		return ans;
    }
};