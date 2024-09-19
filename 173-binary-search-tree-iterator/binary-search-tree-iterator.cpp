class BSTIterator {
private: stack<TreeNode*>myStack;
public:
    void pushAll(TreeNode* node){
        for(; node != NULL; myStack.push(node),node=node->left);
    }
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* temp = myStack.top();
        myStack.pop();
        pushAll(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        return !myStack.empty();
    }
};