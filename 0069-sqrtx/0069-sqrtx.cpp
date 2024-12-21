class Solution {
public:
    int mySqrt(int x) {
        int s = 1, e = x , ans = 0;
        if(x == 0 || x == 1){
            return x;
        }
        while(s<=e){
            int mid = s + (e-s)/2;
            if(mid<=x/mid){
                s = mid + 1;
                ans = mid;
            }else{
                e = mid - 1;
            }
        }
        return ans;
    }
};