class Solution {
public:
    void right(TreeNode* root, vector<int>& ans, int lvl) {
        if (root == nullptr) {
            return;
        }
        if (lvl == ans.size()) {
            ans.push_back(root->val);
        }
        right(root->right, ans, lvl + 1);
        right(root->left, ans, lvl + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        right(root, ans, 0);
        return ans;
    }
};
