class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // if you notic nums1 always have space for the elemet=nts of nums2 even [0] thus filling from by backwards would be the right approach for that O(1) space
        int i = m-1, j = n-1, k = m+n-1;
        // accessing from backwards
        while(i>=0 && j>=0){
            if(nums1[i] > nums2[j]){
                nums1[k] = nums1[i];       // as nums1[i] bada he or hamm piche se bhar rahe he
                i--;
            }else{
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
        // ab agar nums2 me element bache reh jaye to unhe nums1 me simply put kar dena he
        while(j >= 0){
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};