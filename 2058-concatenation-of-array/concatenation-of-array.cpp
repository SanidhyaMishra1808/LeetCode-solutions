class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(2*n);
        int i=0;
        for(int j=0; j<2*n; j++){
            ans[j] = nums[i];
            i++;
            if(i == n){
                i=0;
            }
        }
        return ans;
    }
};