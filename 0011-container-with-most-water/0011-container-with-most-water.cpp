class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0, left = 0, right = height.size()-1,area;
        while(left < right){
            if(height[left] < height[right]){
                area = height[left] * (right - left);
                left++;
            }else{
                area = height[right] * (right - left);
                right--;
            }
            if(area > maxWater){
                maxWater = area;
            }
        }
        return maxWater;
    }
};