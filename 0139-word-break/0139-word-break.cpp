class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n, -1);
        int check = helper(s, wordDict, 0, dp);
        return check == 1;
    }
    int helper(string s, vector<string> &wordDict, int id, vector<int> &dp)
    {
        int n = s.size();
        if(id == n)
        {
            return 1;
        }
        if(dp[id] != -1)
        {
            return dp[id];
        }
        for(string word : wordDict)
        {
            int len = word.size();
            if(id + len <= n && s.substr(id, len) == word)
            {
                if(helper(s, wordDict, id + len, dp) == 1)
                {
                    dp[id] = 1;
                    return dp[id];
                }
            }
        }
        dp[id] = 0;
        return dp[id];
    }
};