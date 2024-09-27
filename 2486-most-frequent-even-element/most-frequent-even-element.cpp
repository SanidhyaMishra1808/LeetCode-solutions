class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                mp[nums[i]]++;
            }
        }
        int freq = 0, ans = -1;
        for (const auto& pair : mp) {
            if (pair.second > freq) {
                ans = pair.first;
                freq = pair.second;
            }
        }
        return ans;
    }
};
