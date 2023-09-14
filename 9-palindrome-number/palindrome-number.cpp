class Solution {
public:
    bool isPalindrome(int x) {
        int actualNum = x;
        if(x<0)return 0;

        long long num = 0;
        while(x>0){
            int digit = x % 10;
            num = num * 10+digit;
            x = x/10;
        }
        if(num==actualNum)return 1;
        return 0;
    }
};