class Solution {
public:
    string removeDuplicates(string s) {
        int start = 0, end = 0;
        while( start < s.length() && end < s.length() ){
            s[end] = s[start];
            if( end > 0 && s[end] == s[end-1])
                end -=2;
            end++;
            start++;
        }
        return s.substr(0, end);
    }
};