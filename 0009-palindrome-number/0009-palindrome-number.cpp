class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        long long int r, sum = 0, temp = x;
        while (x != 0) {
            r = x % 10;
            sum = sum * 10 + r;
            x /= 10;
        }
        return (sum == temp);
    }
};