class Solution {
public:
    bool isValid(TreeNode* root, long minVal, long maxVal) {
        if (root == NULL) {
            return true;
        }
        if (root->val >= maxVal || root->val <= minVal) {
            return false;
        }
        return isValid(root->left, minVal, root->val) &&
               isValid(root->right, root->val, maxVal);
    }
    bool isValidBST(TreeNode* root) { 
        return isValid(root, LONG_MIN, LONG_MAX); 
    }
};