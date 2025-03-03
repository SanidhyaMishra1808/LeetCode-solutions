class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (x == 1) return 1;
        long long p = n; 
        double ans = 1;
        if (p < 0) {
            x = 1 / x;
            if (p == INT_MIN) {
                p++; 
                ans *= x;
            }
            p = -p;
        }
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