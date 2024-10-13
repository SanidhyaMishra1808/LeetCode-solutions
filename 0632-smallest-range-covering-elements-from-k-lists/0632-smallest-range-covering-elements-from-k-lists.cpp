class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        int n = nums.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            int val = nums[i][0];
            mini = min(mini, val);
            maxi = max(maxi, val);
            pq.push({val, i, 0});
        }
        int start = mini;
        int end = maxi;
        while (!pq.empty()) {
            vector<int> top = pq.top();
            int val = top[0];
            int i = top[1];
            int j = top[2];
            pq.pop();
            if (end - start > maxi - val) {
                start = val;
                end = maxi;
            }
            if (j + 1 < nums[i].size()) {
                int temp = nums[i][j + 1];
                maxi = max(temp, maxi);

                pq.push({nums[i][j + 1], i, j+ 1});
            } else {
                break;
            }
        }
        return {start, end};
    }
};