class Solution {
public:
    bool check(vector<long long>& bit, int target) {
        int ans = 0;
        for (int i = 0; i < bit.size(); i++) {
            if (bit[i])
                ans |= (1 << i);
        }
        return ans >= target;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {

        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int ans = INT_MAX;
        int maxi = *max_element(nums.begin(), nums.end());
        if (maxi >= k)
            return 1;

        // bitset stores the binary rep of k
        bitset<30> ref(k);
        vector<long long> bit(30, 0); // stores frequency of bit

        //sliding window
        int l = 0, r = 0;
        while (r < nums.size()) {
            int temp = nums[r];

            for (int i = 0; i < 30; i++) {
                bit[i] += (1 << i) & temp;
            }
            if (check(bit, k)) {
                while (l < nums.size()) {
                    ans = min(ans, r - l + 1);
                    for (int i = 0; i < 30; i++) {
                        bit[i] -= (1 << i) & nums[l];
                        if(bit[i]<0)    bit[i]=0;
                    }
                    l++;
                    if (!check(bit, k)) // if the bitwise OR < k
                        break;
                }
            }
            r++;
        }
        // No subarray found
        if (ans == INT_MAX)
            ans = -1;
        return ans;
    }
};