class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        int n = s.length();

        string temp = "";
        int i = 0;

        while(i<n){
            if(s[i]==' '){
                i++;
            }
            else{
                if(i<n-1 && s[i+1]==' '){
                    temp.push_back(s[i]);
                    if(ans.length()!=0)temp.push_back(' ');
                    ans = temp + ans;
                    temp.erase();
                    i++;
                }
                else if(i==n-1){
                    temp.push_back(s[i]);
                    if(ans.length()!=0) temp.push_back(' ');
                    ans = temp + ans;
                    i++;
                }
                else{
                    temp.push_back(s[i]);
                    i++;
                }
            }
        }
        return ans;
    }
};