class Solution {
public:
    int count(TreeNode* root){
        if(!root) return 0;
        return count(root->left) + count(root->right) +1;
    }
    bool helper(int i, TreeNode* root, int n){
        if(!root) return true;
        if(i>=n) return false;
        bool isLeftValid= helper(2*i+1, root->left,n);
        bool isRightValid= helper(2*i+2, root->right,n);
        return  isLeftValid && isRightValid;

    }
    bool isCompleteTree(TreeNode* root) {
        int n=count(root);
        return helper(0, root, n);
    }
};