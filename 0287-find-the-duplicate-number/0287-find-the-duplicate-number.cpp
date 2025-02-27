class Solution {
public:
// cycle sort
    int findDuplicate(vector<int>& nums) {
        sort(nums);
        int i = 0;
        while(i < nums.size()) {
            if(nums[i] != i + 1) {
                break;
            }
            i++;
        }
        return nums[i];
    }

private:
    void sort(vector<int>& arr) {
        int i = 0;
        while(i < arr.size()) {
            int correct = arr[i] - 1;
            if(arr[i] != arr[correct]) {
                swap(arr, i, correct);
            } else {
                i++;
            }
        }
    }

    void swap(vector<int>& arr, int first, int second) {
        int temp = arr[first];
        arr[first] = arr[second];
        arr[second] = temp;
    }
};
