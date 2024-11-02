class Solution {
public:
    bool isCircularSentence(string s) {
        int n = s.length();
        if (s[0] != s[n - 1]) {
            return false;
        }
        for (int i = 1; i < n - 1; i++) {
            char ch = s[i];
            if (ch == ' ') {
                if (s[i - 1] != s[i + 1]) {
                    return false;
                }
            }
        }
        return true;
    }
};