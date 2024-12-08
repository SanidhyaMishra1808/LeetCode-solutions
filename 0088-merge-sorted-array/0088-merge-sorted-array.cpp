#include <algorithm> // for sort

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = 0;

        // Swap elements to ensure nums1 has the smallest elements
        while (i >= 0 && j < n) {
            if (nums1[i] > nums2[j]) {
                swap(nums1[i--], nums2[j++]);
            } else {
                break;
            }
        }
        // Sort both arrays after the swap
        sort(nums1.begin(), nums1.begin() + m);
        sort(nums2.begin(), nums2.begin() + n);

        // Copy the sorted nums2 back to nums1
        for (int k = 0; k < n; ++k) {
            nums1[m + k] = nums2[k];
        }
    }
};
