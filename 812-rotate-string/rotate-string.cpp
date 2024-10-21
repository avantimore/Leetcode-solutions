class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        if(s.size()!=goal.size()) return false;

        goal+=goal;

        for(int i=0; i<n; i++){
            if(goal.substr(i, n)==s) return true;
        }

        return false;
    }
};