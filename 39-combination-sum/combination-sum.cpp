class Solution {
public:
    void findsol(int i,vector<int>& candidates, int target,vector<vector<int>>&ans, vector<int>ds){
        if(i==candidates.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }
        if(candidates[i] <= target){
            ds.push_back(candidates[i]);
            findsol(i,candidates,target - candidates[i],ans,ds);
            ds.pop_back();
        }
        findsol(i+1,candidates,target,ans,ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        findsol(0,candidates,target,ans,ds);
        return ans;
    }
};