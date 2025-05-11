class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                k--;
            }
            if (k < 0) {
                if (nums[left] == 0) {
                    k++;
                }
                left++;
            }
        }
        return nums.size() - left;
    }
};