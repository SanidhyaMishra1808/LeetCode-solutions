class Solution {
public:
    bool checkTree(TreeNode* root) {
       
        if(root->val == root->right->val + root->left->val){
            return true;
        }else{
            return false;
        }
    }
};