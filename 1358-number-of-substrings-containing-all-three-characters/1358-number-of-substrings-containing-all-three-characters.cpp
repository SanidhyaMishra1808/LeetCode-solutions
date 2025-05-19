class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        unordered_map<char, int> mp;
        int ans = 0;
        int i = 0, j = 0;
        while (j < n) {
            mp[s[j]]++;
            while (mp['a'] >= 1 && mp['b'] >= 1 && mp['c'] >= 1) {
                ans += n - j;
                mp[s[i]]--;
                i++;
            }
            j++;
        }
        return ans;
    }
};