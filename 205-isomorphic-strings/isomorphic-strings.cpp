class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;
        
        unordered_map<char, char> s_to_t; // To map characters from s to t
        unordered_map<char, char> t_to_s; // To map characters from t to s

        for(int i = 0; i < s.length(); i++) {
            char s_char = s[i];
            char t_char = t[i];

            // Check if there is a mapping from s_char to t_char
            if(s_to_t.count(s_char)) {
                if(s_to_t[s_char] != t_char) return false;
            } else {
                s_to_t[s_char] = t_char;
            }

            // Check if there is a reverse mapping from t_char to s_char
            if(t_to_s.count(t_char)) {
                if(t_to_s[t_char] != s_char) return false;
            } else {
                t_to_s[t_char] = s_char;
            }
        }
        return true;
    }
};
