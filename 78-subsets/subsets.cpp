class Solution {
public:
void solution(vector<int>nums, vector<int>output, int index, vector<vector<int>>&ans){
    //basee case
    if(index >= nums.size()){
        ans.push_back(output);
        return;
    }
    //exclude condition
    solution(nums,output,index+1,ans);
    //recursive call (include)
    int element =  nums[index];
    output.push_back(element);
    solution(nums,output,index+1,ans);
}
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>>ans;
       vector<int>output;
       int index = 0;
       solution(nums,output,index, ans);
       return ans; 
    }
};