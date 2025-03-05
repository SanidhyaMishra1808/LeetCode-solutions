class Solution {
public:
    long long coloredCells(int n) {
        if(n == 1){
            return 1;
        }
        long long N = n;
        long long total = (N*N) + ((N-1)*(N-1));
        return total;
    }
};