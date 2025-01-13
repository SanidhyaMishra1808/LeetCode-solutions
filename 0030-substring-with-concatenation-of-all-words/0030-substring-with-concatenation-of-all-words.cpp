class Solution {
public:
    // Helper function to check if a substring can be formed using words
    bool checkSub(unordered_map<string, int> wordCount, string s, int wordLen) {
        for (int j = 0; j < s.size(); j += wordLen) {  // Fixed comma to semicolon
            string w = s.substr(j, wordLen);
            if (wordCount.find(w) != wordCount.end()) {
                if (--wordCount[w] == -1) {  // Decrement count and check if negative
                    return false;
                }
            } else {
                return false; // Word not found
            }
        }
        return true; // Fixed missing semicolon
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int wordLen = words[0].size();  // Fixed variable name from 'word' to 'words'
        int sLen = s.size();
        int wordWindow = words.size() * wordLen;  // Fixed variable name from 'woedWindow' and corrected 'Size()' to 'size()'

        // Build the frequency map for the words
        unordered_map<string, int> wordCount;
        for (int i = 0; i < words.size(); i++) {
            wordCount[words[i]]++;
        }

        // Iterate through the string to find all starting indices
        int i = 0;  // Moved variable declaration to align with usage
        while (i + wordWindow <= sLen) {  // Fixed condition from '<' to '<='
            if (checkSub(wordCount, s.substr(i, wordWindow), wordLen)) {
                res.push_back(i);
            }
            i++;  // Move to the next starting point
        }
        return res;  // Return result containing all valid starting indices
    }
};
