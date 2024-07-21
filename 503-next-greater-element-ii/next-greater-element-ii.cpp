class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>nge(n,-1);
        for(int i=0; i<n; i++){
            for(int j=i+1; j<i+n; j++){
                int index = j % n;
                if(nums[index] > nums[i]){
                    nge[i] = nums[index];
                    break;
                }
            }
        }
        return nge;
    }
};