class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int i = 1;
        int j = 0;
        int count = 1;
        int n = arr.size();

        while(j<n-1 && i<n){
            if(arr[j] != arr[j+1]){
                arr[i] = arr[j+1];
                count++;
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return count;
    }
};