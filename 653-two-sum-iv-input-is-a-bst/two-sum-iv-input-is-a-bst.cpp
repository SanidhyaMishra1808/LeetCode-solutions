class BSTiterator {
    stack<TreeNode*> myStack;
    bool reverse = true;

public:
    BSTiterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    int next() {
        TreeNode* temp = myStack.top();
        myStack.pop();
        if (!reverse) {
            pushAll(temp->right);
        } else {
            pushAll(temp->left);
        }
        return temp->val;
    }

private:
    void pushAll(TreeNode* node) {
        for (; node != NULL;) {
            myStack.push(node);
            if (reverse) {
                node = node->right;
            } else {
                node = node->left;
            }
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) {
            return false;
        }
        BSTiterator l(root, false);
        BSTiterator r(root, true);
        int i = l.next();
        int j = r.next();
        while (i < j) {
            if (i + j == k) {
                return true;
            } else if (i + j < k) {
                i = l.next();
            } else {
                j = r.next();
            }
        }
        return false;
    }
};