class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int maxAltitude = INT_MIN;
        int curr = 0;
        for(int i=0;i<n;i++){
            curr += gain[i];
            maxAltitude = max(maxAltitude,curr);
        }
        if(maxAltitude<0){
            return 0;
        }
        return maxAltitude;
    }
};