class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // Get the number of rows in the triangle
        int row = triangle.size();

        // Create a temporary vector initialized with the values of the last row
        vector<int> temp = triangle[row - 1];

        // Traverse the triangle from the second last row up to the top
        for (int i = row - 2; i >= 0; i--) {
            // Iterate through each element in the current row
            for (int j = 0; j <= i; j++) { // Issue here: 'r' is undeclared and incorrect
                // Update temp[j] with the minimum path sum from the current position
                temp[j] = min(temp[j], temp[j + 1]) + triangle[i][j];
            }
        }

        // Return the minimum path sum starting from the top of the triangle
        return temp[0];
    }
};