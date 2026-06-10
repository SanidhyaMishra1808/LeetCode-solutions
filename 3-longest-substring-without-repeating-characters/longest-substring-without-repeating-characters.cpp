class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low = 0, ans = 0;
        unordered_map<char,int>map;
        for(int high = 0; high<s.length(); high++){
            map[s[high]]++;
            int k = high - low + 1;
            while(map.size() < k){
                map[s[low]]--;
                if(map[s[low]] == 0){
                    map.erase(s[low]);
                }
                low++;
                k = high - low + 1;
            }
            ans = max(ans, high - low + 1);
        }
        return ans;
    }
};