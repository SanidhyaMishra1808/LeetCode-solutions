class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //brute force

        int i = 0;
        int j = 0;
        int index = 0;
        vector<int> nums3(m + n);

        // Merge nums1 and nums2 into nums3
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                nums3[index++] = nums1[i++];
            } else {
                nums3[index++] = nums2[j++];
            }
        }

        // Copy any remaining elements from nums1
        while (i < m) {
            nums3[index++] = nums1[i++];
        }

        // Copy any remaining elements from nums2
        while (j < n) {
            nums3[index++] = nums2[j++];
        }

        // Copy merged elements back into nums1
        for (int i = 0; i < m + n; i++) {
            nums1[i] = nums3[i];
        }
    }
};
