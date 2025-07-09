class Solution {
public:
    void findsol(int ind,vector<int>& nums,vector<vector<int>>&ans, vector<int>&ds) {
        ans.push_back(ds);
        for(int i=ind; i<nums.size(); i++){
// if it's first index in recursion and is = to previous one than pick it on left side of recursion don't pick it for the right side of the recursion
            if(i != ind &&  nums[i] == nums[i-1]){
                continue;
            }
            ds.push_back(nums[i]);
            findsol(i+1, nums, ans, ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        sort(nums.begin(), nums.end());
        findsol(0, nums, ans, ds);
        return ans;
    }
};