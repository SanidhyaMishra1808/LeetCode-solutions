class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        // transpose and then reverse the matrix
        // 1. Transpose
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < m; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // 2. reverse
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};