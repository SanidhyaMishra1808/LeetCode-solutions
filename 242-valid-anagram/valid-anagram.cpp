class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        vector<int> freq(26, 0);
        for (int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++;    // inc freq of that char
            freq[t[i] - 'a']--;    // if that car exist hee -1 freq
        }
        for (int i = 0; i < freq.size(); i++) {
            if (freq[i] != 0) {       // now remaining freq of each char should be 1
                return false;
            }
        }
        return true;
    }
};