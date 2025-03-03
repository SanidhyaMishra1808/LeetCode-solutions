class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int majorElement = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (cnt == 0) {
                majorElement = nums[i];
                cnt++;
            } else if (nums[i] == majorElement) {
                cnt++;
            } else {
                cnt--;
            }
        }
        return majorElement;
    }
};