class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        if(n<3)return 0;

        for(int i=1;i<n-1;i++){
            if((arr[i]%2!=0) && (arr[i-1]%2!=0) && (arr[i+1]%2!=0)){
                return 1;
            }
        }
        return 0;
    }
};