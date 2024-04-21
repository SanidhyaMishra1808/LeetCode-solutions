class Solution {
public:
    string removeDuplicates(string s) {
        int end = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (end > 0 && s[i] == s[end - 1]) {
                end--;
            } else {
                s[end++] = s[i];
            }
        }
        return s.substr(0, end);
    }
};
