class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }     
        int idx = 0, d = 1;
        vector<vector<char>> rows(numRows);
        // +d means down and -d means up; idx+=d shows where to put the values
        for (char c : s) {
            rows[idx].push_back(c);
            if (idx == 0) {
                d = 1;
            } else if (idx == numRows - 1) {
                d = -1;
            }
            idx += d;
        }
        string result;
        for (int i = 0; i < rows.size(); ++i) {
            for (int j = 0; j < rows[i].size(); ++j) {
                result += rows[i][j];
            }
        }
        return result;
    }
};
