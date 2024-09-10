class Solution {
public:
    void inOrder (TreeNode *root, int &cnt){
        if (root == NULL){
            return; 
        }
        inOrder (root -> left, cnt);
            cnt ++;
        inOrder (root -> right, cnt); 
    }
    int countNodes(TreeNode* root) {
        int cnt = 0 ;
        inOrder(root, cnt) ; 
        return cnt ;         
    }
};