class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> lower(26, 0);
        vector<int> upper(26, 0);

        int ans = 0; 
        int odd = 0;

        for (char ch : s) {
            if (islower(ch)) {
                lower[ch - 'a']++;
            } else if (isupper(ch)) {
                upper[ch - 'A']++;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (lower[i] % 2 == 0) {
                ans += lower[i];
            } else {
                ans += lower[i] - 1;
                odd = 1;
            }

            if (upper[i] % 2 == 0) {
                ans += upper[i];
            } else {
                ans += upper[i] - 1;
                odd = 1;
            }
        }

        return ans + odd;
    }
};
