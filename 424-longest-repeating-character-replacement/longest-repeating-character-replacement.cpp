class Solution {
public:
    int characterReplacement(string s, int k) {
        int low = 0, ans = 0, maxCount = 0;
        vector<int>freq(26,0);

        for(int high = 0; high < s.length(); high++){
            freq[s[high] - 'A']++;
            maxCount = max(maxCount, freq[s[high] - 'A']);
            while((high - low + 1) - maxCount > k){
                freq[s[low]-'A']--;
                low++;
            }
            ans = max(ans, high - low + 1);
        }
        return ans;
    }
};