class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> charFrequency;
        int maxLength = 0;
        int windowStart = 0;
        int maxCharCount = 0;
        for (int windowEnd = 0; windowEnd < s.size(); windowEnd++) {
            charFrequency[s[windowEnd]]++;
            maxCharCount = max(maxCharCount, charFrequency[s[windowEnd]]);

            while ((windowEnd - windowStart + 1) - maxCharCount > k) {
                charFrequency[s[windowStart]]--;
                windowStart++;
            }
            maxLength = max(maxLength, windowEnd - windowStart + 1);
        }
        return maxLength;
    }
};