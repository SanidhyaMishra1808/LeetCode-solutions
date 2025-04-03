class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxI(n, 0);
        vector<int> maxK(n, 0);
        maxI[0] = nums[0];
        for (int i = 1; i < n; i++) {
            maxI[i] = max(maxI[i - 1], nums[i - 1]);
        }
        maxK[n - 1] = nums[n - 1];
        for (int k = n - 2; k >= 0; k--) {
            maxK[k] = max(maxK[k + 1], nums[k + 1]);
        }
        long long result = 0;
        for (int j = 1; j < n - 1; j++) {
            result = max(result, (long long)(maxI[j] - nums[j]) * maxK[j]);
        }
        return result;
    }
};