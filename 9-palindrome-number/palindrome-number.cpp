class Solution {
public:
    bool isPalindrome(int x) {
        int org = x;
        if(x<0) return 0;
        long num=0;
        while (x > 0) {
            int digit = x % 10;
            num = num * 10 + digit;
            x = x / 10;
        }
        if(num==org)return 1;
        return 0;
    }
};