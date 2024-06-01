class Solution {
public:
void solution(vector<int>nums, vector<int>output, int i, vector<vector<int>>&ans){
    //basee case
    if(i >= nums.size()){
        ans.push_back(output);
        return;
    }
    //exclude condition
    solution(nums,output,i+1,ans);
    //recursive call (include)
    int element =  nums[i];
    output.push_back(element);
    solution(nums,output,i+1,ans);
}
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>>ans;
       vector<int>output;
       int i = 0;
       solution(nums,output,i, ans);
       return ans; 
    }
};