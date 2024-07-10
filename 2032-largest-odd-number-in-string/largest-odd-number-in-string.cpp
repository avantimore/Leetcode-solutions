class Solution {
public:
    string largestOddNumber(string num) {
        string ans = "";
        int n = num.length();

        int i=n-1;
        for(;i>=0;i--){
            int elem = num[i]-'0';
            if(elem%2!=0)break;
        }
        for(int j = 0;j<=i;j++){
            ans += num[j];
        }
        return ans;
    }
};