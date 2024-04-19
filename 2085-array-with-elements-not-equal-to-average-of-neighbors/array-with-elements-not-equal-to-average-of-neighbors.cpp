class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>ans;
        for(int i=1; i<nums.size(); )
        {
            if(nums[i]>nums[i-1]){
            swap(nums[i],nums[i-1]);
            }
            if(i+1<nums.size() && nums[i]>nums[i+1]){
            swap(nums[i],nums[i+1]);
            }
            i=i+2;
        }
        return nums;
    }
};