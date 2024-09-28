class Solution {
public:
    // Function to reverse the digits of a number
    int rev(int n) {
        int reversed = 0;
        while (n > 0) {
            reversed = reversed * 10 + n % 10;
            n /= 10;
        }
        return reversed;
    }
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        long long count = 0;
        int mod = 1e9 + 7;
        for (int num : nums) {
            int key = num - rev(num);
            count = (count + mp[key]) % mod;
            mp[key]++;
        }

        return count;
    }
};