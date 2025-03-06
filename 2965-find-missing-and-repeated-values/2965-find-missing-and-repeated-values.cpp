class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int N = n * n;
        // create an additional vector to store the frequency of the elements
        vector<int> freq(N + 1, 0);
        // Count frequency
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                freq[grid[i][j]]++;
            }
        }
        int a = 0, b = 0;
        for (int i = 1; i <= N; i++) {
            if (freq[i] == 2) {
                a = i;
            } else if (freq[i] == 0) {
                b = i;
            }
            if (a && b) {
                break;
            }
        }
        return {a, b};
    }
};