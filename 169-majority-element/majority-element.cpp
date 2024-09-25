class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int majo = nums[0];
        for(int i=0; i<nums.size(); i++){
            if(count==0){
                majo = nums[i];
                count = 1;
            }else if(nums[i] == majo){
                count++;
            }else{
                count--;
            }
        }
        return majo;
    }
};