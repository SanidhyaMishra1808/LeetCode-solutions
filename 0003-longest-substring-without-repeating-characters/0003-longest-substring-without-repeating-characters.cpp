class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // sliding window
        int j = 0;
        int maxL = 0;
        unordered_set<char>char_set;
        for(int i=0; i<s.length(); i++){
            while(char_set.find(s[i]) != char_set.end()){
                char_set.erase(s[j]);
                j++;
            }
            char_set.insert(s[i]);
            maxL = max(maxL, i-j+1);
        }
        return maxL;
    }
};