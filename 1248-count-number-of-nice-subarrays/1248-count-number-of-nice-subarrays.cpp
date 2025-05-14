class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int oddCnt = 0;
        int prevCnt = 0;
        int ans = 0;

        int i = 0;
        int j = 0;
        while (j < nums.size()) {
            if (nums[j] % 2 != 0) {
                oddCnt++;
                prevCnt = 0;
            }
            while (oddCnt == k) {
                prevCnt++;
                if (i < nums.size() && nums[i] % 2 == 1) {
                    oddCnt--;
                }
                i++;
            }
            ans += prevCnt;
            j++;
        }
        return ans;
    }
};