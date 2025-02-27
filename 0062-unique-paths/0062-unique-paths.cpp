class Solution {
public:
    int uniquePaths(int m, int n) {
        // this question requires the use of combinatorial formula
        long long res = 1;
        int  tSteps = m + n - 2;
        int downSteps = min(m-1, n-1);
        for(int i=1; i<=downSteps; i++){
            res = res*(tSteps - i + 1) / i;  //combinatoric formula
        }
        return (int)res;
    }
};