class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans = "";
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                int end = i;
                while (i >= 0 && s[i] != ' ') {
                    i--;
                }
                int start = i + 1;
                if (ans == ""){
                    ans = ans + s.substr(start, end - start + 1);
                }else{
                    ans = ans + " " + s.substr(start, end - start + 1);
                }
            }
        }
        return ans;
    }
};