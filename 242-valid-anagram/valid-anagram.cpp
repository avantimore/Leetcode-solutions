class Solution {
public:
    bool isAnagram(string s, string t) {
        int m = s.length();
        int n = t.length();

        if(m!=n)return 0;

        vector<int> alp(26,0);
        for(int i=0;i<n;i++){
            int ch = s[i]-'a';
            alp[ch]++;
        }
        for(int i=0;i<n;i++){
            int ch = t[i]-'a';
            alp[ch]--;
        }
        for(int i=0;i<26;i++){
            if(alp[i]!=0)return 0;
        }
        return 1;
    }
};