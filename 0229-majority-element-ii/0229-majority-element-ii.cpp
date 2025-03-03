class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0;
        int majo1 = 0;
        int count2 = 0;
        int majo2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == majo1) {
                count1++;
            } else if (nums[i] == majo2) {
                count2++;
            } else if (count1 == 0) {
                majo1 = nums[i];
                count1 = 1;
            } else if (count2 == 0) {
                majo2 = nums[i];
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        // Verification part
        vector<int> result;
        int freq1 = 0;
        int freq2 = 0;
        for (int& i : nums) {
            if (i == majo1) {
                freq1++;
            } else if (i == majo2) {
                freq2++;
            }
        }
        int n = nums.size();
        if (freq1 > n / 3) {
            result.push_back(majo1);
        }
        if (freq2 > n / 3) {
            result.push_back(majo2);
        }
        return result;
    }
};
