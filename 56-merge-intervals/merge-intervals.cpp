class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();

        sort(intervals.begin(),intervals.end());
        
        int i=1;
        int first = intervals[0][0],second = intervals[0][1];
        while(i<n){
            int f = intervals[i][0];
            int s = intervals[i][1];

            if(f<=second){
                if(s>second)second = s;
            }
            else{
                ans.push_back({first,second});
                first = f;
                second = s;
            }
            i++;
        }
        ans.push_back({first,second});
        return ans;
    }
};