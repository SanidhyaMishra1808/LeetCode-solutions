class Solution {
public:
    pair<bool, int> isBalancedHelper(TreeNode* root) {
        if (root == NULL) {
            return {true, 0};
        }
        pair<bool, int> left = isBalancedHelper(root->left);
        pair<bool, int> right = isBalancedHelper(root->right);

        bool leftAns = left.first;
        bool rightAns = right.first;
        bool curr = abs(left.second - right.second) <= 1;

        int height = max(left.second, right.second) + 1;
        return {leftAns && rightAns && curr, height};
    }
    bool isBalanced(TreeNode* root) {
        return isBalancedHelper(root).first;
    }
};
