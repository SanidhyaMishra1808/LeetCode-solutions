class Solution {
public:
    void mergeSort(vector<int>& V, int l, int r) {
        //base case
        if(l>=r) {
            return;
        }
        int mid = (l+r)/2;
        mergeSort(V, l, mid);
        mergeSort(V,mid+1, r);
        int lIn = l, rIn = mid+1;
        vector<int> merged;
        while(lIn<=mid && rIn <= r) {
            if(V[lIn]>V[rIn]) {
                merged.push_back(V[rIn]);
                rIn++;
            } else {
                merged.push_back(V[lIn]);
                lIn++;
            }
        }
        while(lIn<=mid) {
            merged.push_back(V[lIn]); lIn++;
        }
        while(rIn<=r) {
            merged.push_back(V[rIn]); rIn++;
        }
        int j = 0;
        for(int i=l;i<=r;i++) {
            V[i] = merged[j];
            j++;
        }
        return;
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};