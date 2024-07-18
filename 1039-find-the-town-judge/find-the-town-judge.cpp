class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (n == 1) return 1;

        // Step 1: Initialize a stack with all people
        stack<int> stk;
        for (int i = 1; i <= n; ++i) {
            stk.push(i);
        }

        // Step 2: Find the potential judge
        while (stk.size() > 1) {
            int a = stk.top(); stk.pop();
            int b = stk.top(); stk.pop();
            if (trusts(a, b, trust)) {
                stk.push(b);
            } else {
                stk.push(a);
            }
        }

        // The potential judge
        int candidate = stk.top();
        stk.pop();

        // Step 3: Verify the candidate
        if (isJudge(candidate, n, trust)) {
            return candidate;
        }
        return -1;
    }

private:
    bool trusts(int a, int b, vector<vector<int>>& trust) {
        for (auto& pair : trust) {
            if (pair[0] == a && pair[1] == b) {
                return true;
            }
        }
        return false;
    }

    bool isJudge(int candidate, int n, vector<vector<int>>& trust) {
        int trustedByCount = 0;
        for (int i = 1; i <= n; ++i) {
            if (i != candidate && trusts(i, candidate, trust)) {
                ++trustedByCount;
            }
        }
        bool trustsNoOne = true;
        for (auto& pair : trust) {
            if (pair[0] == candidate) {
                trustsNoOne = false;
                break;
            }
        }
        return trustedByCount == n - 1 && trustsNoOne;
    }
};
