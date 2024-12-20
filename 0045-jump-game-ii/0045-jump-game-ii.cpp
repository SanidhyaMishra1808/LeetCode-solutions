class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(),farthest = 0, jump = 0, possible_end = 0;
        for(int i=0; i<n-1; i++){
            farthest = max (farthest, i + nums[i]);
            if(i == possible_end){
                jump++;
                possible_end = farthest;
            }
        }
        return jump;
    }
};