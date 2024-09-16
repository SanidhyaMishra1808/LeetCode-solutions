class Solution {
public:
    int result = INT_MIN;
    int solution(TreeNode* root, int start) {
        if (root == NULL) {
            return 0;
        }

        int LH = solution(root->left, start);
        int RH = solution(root->right, start);

        if (root->val == start) {
            result = max(LH, RH);
            return -1;
        } else if (LH >= 0 && RH >= 0) {
            return max(LH, RH) + 1;
        } else {
            int d = abs(LH) + abs(RH);
            result = max(result, d);

            return min(LH, RH) - 1;
        }

        return 0;
    }
    int amountOfTime(TreeNode* root, int start) {
        solution(root, start);
        return result;
    }
};