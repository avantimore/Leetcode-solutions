class Solution {
public:
    int maxVowels(string s, int k) {
        int maxNumOfVowels = INT_MIN;
        bool isVowels = 0;
        bool isVowele = 0;
        int currVowelSum = 0;
        int n = s.length();
        if(s[0] =='a' || s[0] =='e' || s[0] =='i' || s[0] =='o' || s[0] =='u'){
            isVowels = 1;
        }
        for(int i=0;i<k;i++){
            if(s[i] =='a' || s[i] =='e' || s[i] =='i' || s[i] =='o' || s[i] =='u'){
                currVowelSum ++;
            }
        }
        maxNumOfVowels = max(maxNumOfVowels,currVowelSum);
        for(int i=1;i<=n-k;i++){
            if(isVowels==1){
                currVowelSum --;
            }
            if(s[i+k-1] =='a' || s[i+k-1] =='e' || s[i+k-1] =='i' || s[i+k-1] =='o' || s[i+k-1] =='u'){
                currVowelSum++;
            }
            if(s[i] =='a' || s[i] =='e' || s[i] =='i' || s[i] =='o' || s[i] =='u'){
                isVowels = 1;
            }
            else{
                isVowels=0;
            }
            maxNumOfVowels = max(maxNumOfVowels,currVowelSum);
        }
        return maxNumOfVowels;
    }
    //TLE MARLAY
    // int n=s.length();      
        // int maxi=0;
        // for(int i=0;i<=n-k;i++){
        //     int count=0;
        //     for(int j=i;j<k+i;j++){
        //         char ch=s[j];
        //         if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
        //             count++;
        //         }
        //     }
        //     maxi=max(maxi,count);
        // }
        // return maxi;
};