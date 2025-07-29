class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int leftSum = 0, rightSum = 0;
        for (int i = 0; i < k; i++) {
            leftSum += cardPoints[i];
        }
        int maxSum = leftSum;
        for (int i = 0; i < k; i++) {
            leftSum -= cardPoints[k-1-i];
            rightSum += cardPoints[n-1-i];
            maxSum = max(maxSum, leftSum + rightSum);
        }
        return maxSum;
    }
};