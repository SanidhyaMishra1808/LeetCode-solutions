using ll = long long;
const int MOD = 1e9 + 7;
class Solution {
public:
    vector<int> pse(const vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, -1);
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && nums[stk.top()] >= nums[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                left[i] = stk.top();
            }
            stk.push(i);
        }
        return left;
    }
    vector<int> nse(const vector<int>& nums) {
        int n = nums.size();
        vector<int> right(n, n);
        stack<int> stk;
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && nums[stk.top()] > nums[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                right[i] = stk.top();
            }
            stk.push(i);
        }
        return right;
    }
    int sumSubarrayMins(vector<int>& nums) {
        int n = nums.size();
        vector<int> left = pse(nums);
        vector<int> right = nse(nums);
        ll total = 0;
        for (int i=0; i<n; i++) {
            total = (total + (static_cast<ll>(i - left[i]) * (right[i] - i)*nums[i])%MOD)%MOD;
        }
        return total;
    }
};