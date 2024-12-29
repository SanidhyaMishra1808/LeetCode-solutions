class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int candy = 0;
        for(int i=0; i<n; i++){
            candy += 1;
            // Check left and right neighbors
            if (i > 0 && ratings[i - 1] < ratings[i]) {
                candy += 1;
            }
            if (i < n - 1 && ratings[i] > ratings[i + 1]) {
                candy += 1;
            }
        }
        return candy;
    }
};