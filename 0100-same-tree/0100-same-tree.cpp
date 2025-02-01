class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL){
            return true;
        }
        if(p==NULL || q==NULL){
            return false;
        }
        bool left = isSameTree(p->left, q->left);   //checks for leaf
        bool right = isSameTree(p->right, q->right);//checks for leaf
        bool value = (p->val == q->val);            //checks for node values
        return left && right && value;
    }
};