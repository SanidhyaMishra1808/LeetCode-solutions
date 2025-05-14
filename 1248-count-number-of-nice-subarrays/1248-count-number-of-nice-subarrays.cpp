class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int oddCnt = 0;     // Count of odd numbers in the current window
        int prevCnt = 0;    // Count of valid subarrays ending at current j with exactly k odd numbers
        int ans = 0;

        int i = 0;
        int j = 0;
        while (j < nums.size()) {
            if (nums[j] % 2 != 0) {
                oddCnt++;      // Increment odd count when an odd number is found
                prevCnt = 0;   // Reset prevCnt as a new window may start from here
            }

            // When there are exactly k odd numbers in the window
            while (oddCnt == k) {
                prevCnt++;     // Count number of valid starting points for subarrays ending at j
                if (i < nums.size() && nums[i] % 2 == 1) {
                    oddCnt--;  // Shrink window from left if an odd is removed
                }
                i++;
            }

            ans += prevCnt;    // Add all valid subarrays ending at j
            j++;
        }
        return ans;
    }
};