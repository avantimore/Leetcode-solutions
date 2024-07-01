class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int count = 1;
        int n = arr.size();
        if(n==1)return 1;

        int i = 1;
        int j = 1;

        while(i<n && j<n){
            if(arr[j]==arr[j-1])j++;
            else{
                arr[i++] = arr[j++];
                count++;
            }
        }
        return count;
    }
};