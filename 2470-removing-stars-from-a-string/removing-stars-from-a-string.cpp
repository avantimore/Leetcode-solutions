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
            int m = tempans.length();
            for (int i = 0; i < m / 2; i++) {
                swap(tempans[i], tempans[m - i - 1]);
            }
        // string ans="";
        // int m = tempans.length();
        // for(int i=m-1;i>=0;i--){
        //     ans.push_back(tempans[i]);
        // }
        return tempans;
    }
// string removeStars(string s) {
//     stack<char> st;
//     int n = s.length();
    
//     for (int i = 0; i < n; i++) {
//         if (s[i] >= 'a' && s[i] <= 'z') {
//             st.push(s[i]);
//         } else if (s[i] == '*') {
//             if (!st.empty()) {
//                 st.pop();
//             }
//         }
//     }
    
//     string ans = "";
    
//     while (!st.empty()) {
//         ans.push_back(st.top());
//         st.pop();
//     }
    
//     // Reverse the ans string in place
//     int m = ans.length();
//     for (int i = 0; i < m / 2; i++) {
//         swap(ans[i], ans[m - i - 1]);
//     }
    
//     return ans;
// }


};