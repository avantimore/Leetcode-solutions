class Solution {
public:
    // int longestOnes(vector<int>& nums, int k) {
    //     int countZeros=k;
    //     int n = nums.size();
    //     int maxi = 0;
    //     int cnt = 0;
    //     for(int i=0;i<n;i++){
    //         if(nums[i]==1){
    //             cnt++;
    //             maxi = max(maxi,cnt);
    //         }
    //         else if(nums[i]==0 && k!=0){
    //             cnt++;
    //             maxi = max(maxi,cnt);
    //             countZeros--;
    //         }
    //         else{
    //             cnt=0;
    //             countZeros=k;
    //         }
    //     }
    //     return maxi;
    // }

    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0;
        while(j<nums.size()){
            if(nums[j]==0){
                k--;
            }
            if(k<0){
                if(nums[i]==0){
                    k++;
                }
                i++;
            }
            j++;
        }
        return j-i;
    }   
};