/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    void trav(Node* root, vector<int>& ans) {
        if (!root) {
            return;
        }
        ans.push_back(root->val);
        for (auto i : root->children){
            trav(i, ans);
        }
    }
    vector<int> preorder(Node* root) {
        vector<int> ans;
        trav(root, ans);
        return ans;
    }
};