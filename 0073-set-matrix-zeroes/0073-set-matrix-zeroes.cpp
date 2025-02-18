class Solution {
public:
    void markRow(vector<vector<int>>& matrix, int i, int m) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] != 0) {
                matrix[i][j] = -1;
            }
        }
    }

    void markCol(vector<vector<int>>& matrix, int j, int n) {
        for (int i = 0; i < n; i++) {
            if (matrix[i][j] != 0) {
                matrix[i][j] = -1;
            }
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        // Traverse the matrix to find zeroes and mark rows and columns
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    markRow(matrix, i, m);
                    markCol(matrix, j, n);
                }
            }
        }

        // Convert all -1s back to 0s
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {  // Corrected: j < m instead of j < n
                if (matrix[i][j] == -1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
