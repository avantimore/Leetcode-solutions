class Solution {
public:
int reverse(int k) {
    long x=k;
    bool flag = false;
    long num = 0;

    if (x < 0) {
        flag = true;
        x = -x;
    }

    while (x > 0) {
        int digit = x % 10;
        num = num * 10 + digit;
        x = x / 10;
    }

    if (flag) {
        num = -num;
    }

    if (num > INT_MAX || num < INT_MIN) {
        return 0;
    }

    return (int)num;
}

};