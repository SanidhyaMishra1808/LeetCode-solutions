class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int low = 0, zero_count = 0, ans = 0;
        for(int high =0; high<nums.size(); high++){
            if(nums[high] == 0){
                zero_count++;
            }
            while(zero_count > k){
                if(nums[low] == 0){
                    zero_count--;
                }
                low++;
            }
            ans = max(ans, high - low + 1);
        }
        return ans;
    }
};