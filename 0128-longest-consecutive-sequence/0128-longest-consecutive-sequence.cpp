class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        unordered_set<int> st(nums.begin(), nums.end());
        int longest = 0;

        for (int num : st) {
            if (st.find(num - 1) == st.end()) {
                int cnt = 1;
                int x = num;
                while (st.find(x + 1) != st.end()) {
                    x++;
                    cnt++;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};
