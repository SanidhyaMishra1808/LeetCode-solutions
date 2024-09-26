class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        for(int i=1; i<n-1; i++){
            if(nums[i] == nums[i-1]){
                continue;
            }
            int left = i-1, right = i+1;
            //search for element in right
            while(right < n && nums[i] == nums[right]){
                right++;
            }
            //search for element in left
            while(left >= 0 && nums[i] == nums[left]){
                left--;
            }
            //edge case
            if(right >= n || left < 0){
                continue;
            }
            // hill case
            if(nums[i] > nums[left] && nums[i] > nums[right]){
                cnt++;
            }
            // valley case
            else if(nums[i] < nums[left] && nums[i] < nums[right]){
                cnt++;
            }
        }
        return cnt;
    }
};