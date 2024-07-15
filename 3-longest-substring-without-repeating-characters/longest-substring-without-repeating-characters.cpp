class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxi = 0;
        for(int i=0;i<n;i++){
            unordered_map<char,int> mp;
            for (int j = i; j < n; j++) {
                if (mp.find(s[j]) == mp.end()) {
                    mp[s[j]] = j;
                    maxi = max(maxi, j - i + 1); 
                } else {
                    break; 
                }
            }
        }
        return maxi;
    }
};