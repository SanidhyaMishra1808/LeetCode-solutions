class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool FR = false, FC = false;

        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                FR = true;
            }
        }

        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                FC = true;
            }
        }
// converting  entire row and col to 0
// here we start loops from i=1 and j=1 because we have already checked the first row and col by FR and FC 
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if(FR){
            for(int j=0; j<n; j++){
                matrix[0][j] = 0;
            }
        }
        if(FC){
            for(int i=0; i<m; i++){
                matrix[i][0] = 0;
            }
        }
    }
};