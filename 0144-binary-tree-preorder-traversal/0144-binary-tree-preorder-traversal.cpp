class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==nullptr) return {};
        vector<int> v;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode* node = s.top();
            s.pop();
            v.push_back(node->val);
            if(node->right) s.push(node->right);
            if(node->left) s.push(node->left);
        }
        return v;
    }
};