class Solution {
public:
    string removeStars(string s) {
        string tempans="";
        stack<char> st;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(s[i]>='a' && s[i]<='z'){
                st.push(s[i]);
            }
            else if(s[i]=='*'){
                st.pop();
            }
        }
        while(!st.empty()){
            char stop = st.top();
            st.pop();
            tempans.push_back(stop);
        }
        string ans="";
        int m = tempans.length();
        for(int i=m-1;i>=0;i--){
            ans.push_back(tempans[i]);
        }
        return ans;
    }
};