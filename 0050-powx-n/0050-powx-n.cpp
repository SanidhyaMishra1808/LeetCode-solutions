class Solution {
public:
    double myPow(double x, int n) {
        // case for when either x or n = 0,1
        if (x == 0)
            return 0;
        if (n == 0)
            return 1;

        // now their lies two main cases
        // 1. for negative power
        long long p = n;
        double ans = 1;
        if (p < 0) {
            x = 1 / x; // 5^(-2) == 1 / 5^(2)
            if (p == INT_MIN) {
                p++;
                ans *= x;
            }
            p = -p;
        }
        // 2. for positive powers
        while (p > 0) {
            if (p % 2 == 1) {
                ans *= x;
                p--;
            } else {
                x *= x;
                p /= 2;
            }
        }
        return ans;
    }
};