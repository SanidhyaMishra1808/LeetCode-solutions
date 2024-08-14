class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0, sum = 0;
        int len = INT_MAX;
        while(right < n){
            sum = sum + nums[right];
            while(sum >= target){
                len = min(len, right-left+1);
                sum = sum - nums[left];
                left++;
            }
            right++;
        }
        return len == INT_MAX ? 0 : len;
    }
};