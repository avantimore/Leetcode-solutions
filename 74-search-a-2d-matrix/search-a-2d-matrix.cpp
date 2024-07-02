class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int noCol = matrix[0].size();
        int noRow = matrix.size();

        int n = (noCol*noRow);

        int s=0,e = n-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            int r = mid / noCol;
            int c = mid % noCol;

            if(matrix[r][c]==target)return 1;
            if(matrix[r][c]<target){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return 0;
    }
};