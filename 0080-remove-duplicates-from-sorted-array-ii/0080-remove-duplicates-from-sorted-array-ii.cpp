class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 1;
        int n = nums.size();
        if(n<2){
            return n;
        }
        for (int i = 1; i < n; i++) {
            if (j == 1 || nums[i] != nums[j - 2]) {
                nums[j++] = nums[i];
            }
        }
        return j;
    }
};