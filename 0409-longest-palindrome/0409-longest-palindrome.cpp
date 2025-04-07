class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        int ans = 0;
        bool odd_found = false;
        for (auto& pair : freq) {
            int count = pair.second;
            if (count % 2 == 0) {
                ans += count;
            } else {
                ans += count - 1;
                odd_found = true;
            }
        }
        if (odd_found) {
            ans += 1;
        }
        return ans;
    }
};