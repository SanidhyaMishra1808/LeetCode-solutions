class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustCount(n + 1, 0);
        vector<int> trustedByCount(n + 1, 0);
        for(int i = 0; i < trust.size(); i++){
            int a = trust[i][0];
            int b = trust[i][1];
            trustCount[a]++;
            trustedByCount[b]++;
        }
        for(int i = 1; i <= n; i++){
            if(trustCount[i] == 0 && trustedByCount[i] == n - 1){
                return i;
            }
        }
        return -1;
    }
};