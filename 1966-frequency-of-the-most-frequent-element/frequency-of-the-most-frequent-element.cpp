class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long left = 0;
        long right = 0;
        long sum = 0;
        long length = 0;
        while (right < nums.size()) {
            sum += nums[right];
            while (nums[right] * (right - left + 1) > sum + k) {
                sum -= nums[left];
                left++;
            }
            length = max(length, right - left + 1);
            right++;
        }
        return length;
    }
};