class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> nums = arr;
        unordered_map<int, int> mp;
        sort(nums.begin(), nums.end());

        for (int a : nums) {
            if (!mp.contains(a)) {
                mp[a] = mp.size() + 1;
            }
        }
        for (int& a : arr) {
            a = mp[a];
        }
        return arr;
    }
};