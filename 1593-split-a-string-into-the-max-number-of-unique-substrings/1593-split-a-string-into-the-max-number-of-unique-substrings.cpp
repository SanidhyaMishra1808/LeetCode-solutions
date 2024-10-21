class Solution {
public:
    void solve(string& s, int ind, unordered_set<string>& st, int currCount, int& maxCount) {
        int n=s.length();
        if(currCount + (n - ind) <= maxCount) { 
            return;
        }
        if(ind == n) {
            maxCount = max(maxCount, currCount);
        }
        for(int j = ind; j < n; j++) {
            string sub = s.substr(ind, j-ind+1);
            if(st.find(sub) == st.end()) {
                st.insert(sub);
                solve(s, j+1, st, currCount+1, maxCount);
                st.erase(sub);
            }
        }
    }
    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        int maxCount  = 0;
        int currCount = 0;
        solve(s, 0, st, currCount, maxCount);

        return maxCount;
    }
};