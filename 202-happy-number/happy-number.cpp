class Solution {
public:
    int helper(int n){
        int ans = 0;
        while(n){
            int temp = n % 10;
            ans += (temp * temp);
            n /= 10;
        }
        return ans;
    }
    
    bool isHappy(int n) {
        int slow = n, fast = helper(n);
        while(slow != fast){
            slow = helper(slow);
            fast = helper(helper(fast));
        }
        return slow == 1;
    }
};
