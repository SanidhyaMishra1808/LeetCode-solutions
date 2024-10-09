class Solution {
public:
    int minSubarray(vector<int>& a, int p) {

        int n = a.size();
        vector<long long> ps(n);
        ps[0] = a[0];
        long long s = a[0];
        for (int i = 1; i < n; i++) {
            s += a[i];
            ps[i] = a[i] + ps[i - 1];
            if ((i - 3) >= 0)
                cout << ps[i] - ps[i - 3] << " ";
        }
        cout << endl;
        cout << "sum is :: " << s << endl;
        cout << "rem is :: " << s % p << endl;

        if ((s % p) == 0)
            return 0;
        int x = s % p;
        unordered_map<long long, int> m;
        long long sum = 0;
        int ans = 1e6;
        m[0] = -1;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            int rem = sum % p;
            int k = (rem - x + p) % p;
            if (m.find(k) != m.end()) {
                ans = min(ans, i - m[k]);
                m[rem] = i;
            } else
                m[rem] = i;
        }

        if (ans == 1e6 || ans == n)
            ans = -1;
        return ans;
    }
};