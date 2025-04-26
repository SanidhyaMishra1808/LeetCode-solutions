class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-2; // to find the first decreasing element 
        while( i>= 0 && nums[i] >= nums[i+1]){
            i--;//first decreasing element
        }
        if(i >= 0){
            int j = n-1;
            while(nums[j] <= nums[i]){
                j--;//next larger element
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin()+i+1, nums.end());// reverse the right half [ x _ _ ]
    }
};