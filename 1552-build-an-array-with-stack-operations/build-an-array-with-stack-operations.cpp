class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>ans;
        vector<int>stack;
        int j = 0;
        for(int i=1; i<=n; i++){    //loop will start from 1 as we need to check the first top
            if(stack == target){
                return ans;
            }
            if(i == target[j]){
                stack.push_back(i);
                ans.push_back("Push");
                j++;
            }else{
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};