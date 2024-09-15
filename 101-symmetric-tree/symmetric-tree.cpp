class Solution {
public:
    bool sym(TreeNode* left, TreeNode* right){
        if(left == NULL || right == NULL){
            return left == right;
        }
        if(left->val != right->val){
            return false;
        }
        return sym(left->left, right->right) && sym(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        return root==NULL || sym(root->left, root->right);
    }
};