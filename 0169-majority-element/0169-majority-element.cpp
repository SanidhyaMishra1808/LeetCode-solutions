class Solution {
public:
    int majorityElement(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int currentElement = nums[0];
        int currentCount = 1;
        int maxCount = 1;
        int majorityElement = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == currentElement) {
                currentCount++;
            } else {
                currentElement = nums[i];
                currentCount = 1;
            }
            if (currentCount > maxCount) {
                maxCount = currentCount;
                majorityElement = nums[i];
            }
        }

        return majorityElement;
    }
};
