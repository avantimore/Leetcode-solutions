class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        std::stack<char> st;
        for(int i = 0; i < n; i++) {
            char ch = s[i];
            if(ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            } else if(ch == ')') {
                if(st.empty() || st.top() != '(') return false;
                st.pop();
            } else if(ch == '}') {
                if(st.empty() || st.top() != '{') return false;
                st.pop();
            } else if(ch == ']') {
                if(st.empty() || st.top() != '[') return false;
                st.pop();
            }
        }
        return st.empty();
    }
};