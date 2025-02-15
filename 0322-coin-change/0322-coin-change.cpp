class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    int coinChange(vector<int>& c, int a) {
        vector<int> dp(a + 1, a + 1);
        dp[0] = 0;
        for (int i = 1; i <= a; ++i) {
            for (int coin : c) {
                if (i - coin >= 0) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp[a] > a ? -1 : dp[a];
    }
};