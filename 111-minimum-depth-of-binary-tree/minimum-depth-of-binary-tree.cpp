class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        queue<TreeNode*>q;
        q.push(root);
        int lvl = 1;
        while(!q.empty()){
            int lvlsize = q.size();
            for(int i=0; i<lvlsize; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left == NULL && node->right==NULL){
                    return lvl;
                }if(node->left != NULL){
                    q.push(node->left);
                }if(node->right != NULL){
                    q.push(node->right);
                }
            }
            lvl++;
        }
        return lvl;
    }
};