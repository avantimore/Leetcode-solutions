class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        int mid = 0;
        int e = n-1;

        while(mid<=e){
            if(nums[mid]==0){
                swap(nums[mid++],nums[s++]);
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid],nums[e--]);
            }

            for(int i=0;i<n;i++){
                cout<<nums[i]<<" ";
            }
            cout<<endl;
        }

    }
};