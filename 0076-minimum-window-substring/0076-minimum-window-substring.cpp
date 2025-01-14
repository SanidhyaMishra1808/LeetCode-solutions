class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> map;
        int minLen = INT_MAX;
        int start = -1;
        int left = 0;
        int count = 0;
        for (char c : t) {
            map[c]++;
        }
        
        int required = map.size();
        for (int right = 0; right < s.length(); right++) {
            if (map.find(s[right]) != map.end()) {
                map[s[right]]--;
                if (map[s[right]] == 0) {
                    count++;
                }
            }
            while (count == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }
                if (map.find(s[left]) != map.end()) {
                    if (map[s[left]] == 0) {
                        count--;
                    }
                    map[s[left]]++;
                }
                left++;
            }
        }
        if (start == -1) {
            return "";
        }
        return s.substr(start, minLen);
    }
};