class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0,r=0;
        int n = s.length();
        int maxi = 0;
        unordered_map<char,int> mp;

        while(r<n){
            if (mp.find(s[r]) == mp.end()) {
                mp[s[r]]=1;
                maxi = max(maxi, r - l + 1); 
                r++;
            }
            else{
                auto iter = mp.find(s[l]); 
                if (iter != mp.end()) { 
                    mp.erase(iter); 
                }
                l++;
            }
        }
        return maxi;
    }
};