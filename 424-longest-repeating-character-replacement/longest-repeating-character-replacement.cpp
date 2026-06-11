class Solution {
public:
    int characterReplacement(string s, int k) {
        int low = 0, ans = 0, maxCount = 0;
        vector<int>freq(27,0);

        for(int high = 0; high < s.length(); high++){
            freq[s[high] - 'A']++;   // particular character ki freq increase karte hue
            maxCount = max(maxCount, freq[s[high] - 'A']);
            int len = high - low + 1;
            int diff = len - maxCount;
            if(diff > k){
                freq[s[low]-'A']--;
                maxCount = 0;
                low++;
            }
            if(diff <= k){
                ans = max(ans, len);
            }
        }
        return ans;
    }
};