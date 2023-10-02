class Solution {
public:
     bool check(char ch){
        vector<char> vow = {'a','e','i','o','u'};
        for(int j = 0; j< vow.size(); j++){
            if(ch == vow[j]) return true;
        }
        return false;
    }
    int maxVowels(string s, int k) {
    
        int cnt = 0;
        for(int i = 0; i< k; i++){
            if(check(s[i])) cnt++;
        }
        int ans = cnt;
        int j = k, i = 0;
        while(j < s.length()){
            if(check(s[j])){
                cnt++;
            }
            if(check(s[i])){
                cnt--;
            }
            ans = max(cnt, ans);
            i++;
            j++;
        }
        return ans;
    }
};