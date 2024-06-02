class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, int ind){
        //base case
        if(ind >=nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=ind; i<nums.size(); i++){
            swap(nums[ind], nums[i]);
            //backtrack
            solve(nums, ans, ind+1);
            swap(nums[ind], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums){
        vector<vector<int>>ans;
        int index = 0;
        solve(nums, ans, 0);
        return ans;
    }
};