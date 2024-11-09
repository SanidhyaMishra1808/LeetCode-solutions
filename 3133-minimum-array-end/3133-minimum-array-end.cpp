class Solution {
public:
    long long minEnd(int n, int x) {
        bitset<64> _x(x);
        bitset<64> _n(n - 1);
        int i = 0, j = 0;
        while (i < 64 && j < 64) {
            if (!_x[i])
                _x[i] = _n[j++];
            i++;
        }
        return _x.to_ullong();
    }
};