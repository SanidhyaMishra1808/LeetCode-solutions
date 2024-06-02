class Solution {
public:
    void findsol(int ind, vector<int>& candidates, int target,vector<vector<int>>&ans, vector<int>& ds) {
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        for(int i =ind; i<candidates.size(); i++){
            if(i >ind && candidates[i] == candidates[i-1]){
                continue;
            }
            if(candidates[i] > target){
                break;
            }
            ds.push_back(candidates[i]);
            findsol(i+1,candidates,target-candidates[i],ans,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>ds;
        vector<vector<int>>ans;
        findsol(0,candidates,target,ans,ds);
        return ans;
    }
};