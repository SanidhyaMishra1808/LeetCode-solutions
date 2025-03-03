class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int left = 0, right = nums.size() - 1;
        vector<int>ans(nums.size(), 0);
        for (int i = 0, j = nums.size() - 1; i < nums.size(); ++i, --j) {
            if (nums[i] < pivot) {
                ans[left] = nums[i];
                left++;
            }
            if (nums[j] > pivot) {
                ans[right] = nums[j];
                right--;
            }
        }
        while (left <= right) {
            ans[left] = pivot;
            left++;
        }
        return ans;
    }
};