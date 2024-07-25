class Solution {
public:
    string removeKdigits(string nums, int k) {
        stack<int> st;
        for (int i = 0; i < nums.length(); i++) {
            while (!st.empty() && k > 0 && (nums[i] - '0') < st.top()) {
                st.pop();
                k--;
            }
            st.push(nums[i] - '0');
        }
        while (k > 0) {
            st.pop();
            k--;
        }
        string ans = "";
        while (!st.empty()) {
            ans += (char)(st.top() + '0');
            st.pop();
        }
        while (ans.size() != 0 && ans.back() == '0') {
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        if (ans.empty()) {
            return "0";
        } else {
            return ans;
        }
    }
};