class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<int> ans;
        int n = arr.size();

        int cnt =1;
        for(int i=0;i<arr.size();i++){
            cout<<arr[i]<<" ";
        }
        for(int i=1;i<=n;i++){
            if(i==n){
                if(arr[n-1]==arr[n-2]){
                    // cnt++;
                    ans.push_back(cnt);
                    
                }
                else{
                    ans.push_back(1);
                }
                break;
            }
            if(arr[i]==arr[i-1]){
                cnt++;
            }
            else{
                ans.push_back(cnt);
                cnt=1;               
            }
        }
        cout<<endl;
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        sort(ans.begin(),ans.end());
        
        for(int i=1;i<ans.size();i++){
            if(ans[i]==ans[i-1]){
                return false;
            }
        }
        return true;
    }
};