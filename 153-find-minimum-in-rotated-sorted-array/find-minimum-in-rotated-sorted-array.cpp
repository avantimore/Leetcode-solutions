class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        if(n==2)return min(arr[0],arr[1]);
        if(n==1 || arr[0]<arr[n-1])return arr[0];

        int first = arr[0];
        int last = arr[n-1];

        int s = 1;
        int e = n-2;
        int ans =INT_MIN;

        while(s<=e){
            int mid = s+(e-s)/2;
            if(arr[mid]>first && arr[mid]>last){
                s = mid+1;
            }
            else if(arr[mid]<first && arr[mid]<last){
                ans = arr[mid];
                e = mid-1;
            }
        }
        if(ans==INT_MIN){
            return min(first,last);
        }
        return ans;
    }
};