class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long sum = 0; 
        for(int i=0; i<nums.size(); i++){
            int largest = nums[i], smallest = nums[i];
            for(int j=i; j<nums.size(); j++){
                largest = max(largest, nums[j]);
                smallest = min(smallest, nums[j]);
                sum += (largest - smallest);
            }
        }
        return sum; 
    }
};