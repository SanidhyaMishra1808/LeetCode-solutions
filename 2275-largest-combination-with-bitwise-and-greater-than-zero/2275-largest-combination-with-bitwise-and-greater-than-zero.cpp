class Solution {
public:
    int largestCombination(vector<int>& c) {
        vector<int> v(32,0);
        for(auto it : c){
            for(int i = 31; i>=0; i--){
                int k = it >> i;
                if(k & 1) v[i]++;
            }
        }
        int ans = 0;
        for(int i = 0; i<32; i++){
            ans = max(ans,v[i]);
        }
        return ans;
    }
};