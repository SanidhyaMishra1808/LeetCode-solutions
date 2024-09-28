#include <vector>
#include <unordered_map>
using namespace std;

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

    // Function to count nice pairs
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        long long count = 0;
        int mod = 1e9 + 7; // Modulo value to prevent overflow
        
        for (int num : nums) {
            int key = num - rev(num);
            count = (count + mp[key]) % mod;
            mp[key]++;
        }

        return count;
    }
};