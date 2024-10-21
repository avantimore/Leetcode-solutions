class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0,maxCnt=0;
        int n = s.length();
        for(int i=0;i<n;i++){
            char ch = s[i];
            if(ch=='('){
                cnt++;
                maxCnt = max(cnt,maxCnt);
            }
            else if(ch==')'){
                cnt--;
            }
        }
        return maxCnt;
    }
};