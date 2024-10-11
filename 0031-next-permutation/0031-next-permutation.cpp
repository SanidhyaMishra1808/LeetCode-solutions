class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int firstDecreasingIndex = -1;
        for (int i = n - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                firstDecreasingIndex = i - 1;
                break;
            }
        }

        if (firstDecreasingIndex != -1) {
            int nextLargerIndex = firstDecreasingIndex + 1;
            for (int i = n - 1; i > firstDecreasingIndex; i--) {
                if (nums[i] > nums[firstDecreasingIndex]) {
                    nextLargerIndex = i;
                    break;
                }
            }
            swap(nums[firstDecreasingIndex], nums[nextLargerIndex]);
        }
        reverse(nums.begin() + firstDecreasingIndex + 1, nums.end());
    }
};
