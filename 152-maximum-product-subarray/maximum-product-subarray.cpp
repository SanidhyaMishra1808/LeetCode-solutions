class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long maxi = INT_MIN;
        long long prod = 1;
        //left to right loop
        for (int i = 0; i < nums.size(); i++) {
            if(prod==1000000000){
                break;
            }
            prod *= nums[i];
            maxi = max(prod, maxi);
            if (prod == 0){
                prod = 1;
            }
        }
        prod = 1;
        // right to left loop
        for (int i = nums.size() - 1; i >= 0; i--) {
            if(prod==1000000000){
                break;
            }
            prod *= nums[i];
            maxi = max(prod, maxi);
            if (prod == 0){
                prod = 1;
            }
        }
        return maxi;
    }
};