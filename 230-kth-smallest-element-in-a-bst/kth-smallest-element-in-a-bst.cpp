class Solution {
public:
    void inorder(TreeNode* root, int k, int& ans, int& count) {
        if (root == NULL) {
            return;
        }
        inorder(root->left, k, ans, count);
        count++;
        if (count == k) {
            ans = root->val;
            return;
        }
        inorder(root->right, k, ans, count);
    }
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int ans = -1;
        inorder(root, k, ans, count);
        return ans;
    }
};