class Solution {
private: 
    void merge(vector<int>& nums, int low, int mid, int high, int& Cnt){
        int j = mid+1;
        for(int i=low; i<=mid; i++){
            while(j<=high && nums[i] > 2*(long long)nums[j]){
                j++;
            }
            Cnt += j-(mid+1);
        }
        int size = high-low+1;
        vector<int> temp(size, 0);
        int left = low, right = mid+1, k=0;
        while(left<=mid && right<=high){
            if(nums[left] < nums[right]){
                temp[k++] = nums[left++];
            }
            else{
                temp[k++] = nums[right++];
            }
        }
        while(left<=mid){
            temp[k++] = nums[left++]; 
        }
        while(right<=high){
            temp[k++] = nums[right++]; 
        }
        int m=0;
        for(int i=low; i<=high; i++){
            nums[i] = temp[m++];
        }
    }
    void mergeSort(vector<int>& nums, int low, int high, int& Cnt){
        if(low >= high){
            return;
        }
        int mid = (low + high) >> 1;
        mergeSort(nums, low, mid, Cnt);
        mergeSort(nums, mid+1, high, Cnt);
        merge(nums, low, mid, high, Cnt);
    }
public:
    int reversePairs(vector<int>& nums) {
        int Cnt = 0;
        mergeSort(nums, 0, nums.size()-1, Cnt);
        return Cnt;
    }
};