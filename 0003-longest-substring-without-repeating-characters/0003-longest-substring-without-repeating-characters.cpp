class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int cnt = 0;
        int element = 0;
        unordered_set<char> st;
        for (int i = 0; i < n; i++) {
            // ab agar yaha se s[i] element st me already he to wo check kart he
            // (initially empty)
            while (st.find(s[i]) != st.end()) {
                st.erase(s[element]);
                element++;
            }
            st.insert(s[i]);
            cnt = max(cnt, i- element + 1);//{i-element+1} = window size
        }
        return cnt;
    }
};