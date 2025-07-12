class Solution {
public:
    vector<vector<int>> generate(int numRows) {
    // in 2d matrix we can not initaialize all the element with 1 by using <int>>ans(numRows, 1) because each initializes row with 1 nit the 1st vector inside the main vector;
        vector<vector<int>> ans(numRows);
        for (int i = 0; i < numRows; i++) {
            ans[i].resize(i + 1, 1);
            for (int j = 1; j < i; j++) {
                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
        }
        return ans;
    }
};