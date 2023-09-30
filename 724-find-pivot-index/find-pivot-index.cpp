class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // long long backSum = 0;
        // int n = nums.size();
        // for(int i=1;i<n;i++){
        //     backSum +=nums[i];
        // }
        // if(backSum==0){
        //     return 0;
        // }
        // long long frontSum = nums[0];
        // for(int i=1;i<n;i++){
            
        //     backSum -= nums[i];
        //     if(backSum==frontSum){
        //         return i;
        //     }
        //     frontSum +=nums[i];
        // }
        // if(frontSum-nums[n-1]==0){
        //     return n-1;
        // }
        // return -1;

        int totalWeightOnLeft = 0;
        int totalWeightOnRight = std::accumulate( nums.begin(), nums.end(), 0);
        
        
        for(std::size_t i = 0; i < nums.size() ; i++ ){
            
            int currentWeight = nums[i];
            
            totalWeightOnRight -= currentWeight;
            
            if( totalWeightOnLeft == totalWeightOnRight ){
                // balance is met on both sides
                return i;
            }
            
            totalWeightOnLeft += currentWeight;
        }
        
        
        return -1;
    }
};