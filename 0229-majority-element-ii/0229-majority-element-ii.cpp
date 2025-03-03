class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        // if(n/3 < 1){
        //     return nums;
        // }
        vector<int> ans;
        int count1 = 0;
        int count2 = 0;
        int major1 = 0;
        int major2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == major1) {
                count1++;
            } else if (nums[i] == major2) {
                count2++;
            } else if (count1 == 0) {
                major1 = nums[i];
                count1 = 1;
            } else if (count2 == 0) {
                major2 = nums[i];
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        int freq1 = 0;
        int freq2 = 0;
        for (int& i : nums) {
            if (i == major1) {
                freq1++;
            } else if (i == major2) {
                freq2++;
            }
        }
        if (freq1 > n / 3) {
            ans.push_back(major1);
        }
        if (freq2 > n / 3) {
            ans.push_back(major2);
        }
        return ans;
    }
};