class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int left = 0;
        int cnt = 0;
        unordered_set<char>window;
        for(int i=0; i<n; i++){
            while(window.find(s[i]) != window.end()){
                window.erase(s[left]);
                left++;
            }
            window.insert(s[i]);
            cnt = max(cnt, i - left + 1);
        }
        return cnt;
    }
};