class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q){
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p , q);
        TreeNode* right = lowestCommonAncestor(root->right, p , q);
        // result
        if(left == NULL){
            return right;
        }else if(right == NULL){
            return left;
        }else{
            // if both of them are not null then this one is the common ancestor
            return root;
        }
    }
};