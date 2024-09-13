/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;  // flag to reverse the flow

        while (!q.empty()) {
            int size = q.size();
            vector<int> ans(size);

            // Level process
            for (int i = 0; i < size; ++i) {
                TreeNode* frontNode = q.front();
                q.pop();  // pop the front node
                
                // Determine index based on the direction
                int index = leftToRight ? i : size - i - 1;
                ans[index] = frontNode->val;

                // If the node's children are not null, push them into the queue
                if (frontNode->left) {
                    q.push(frontNode->left);
                }
                if (frontNode->right) {
                    q.push(frontNode->right);
                }
            }

            // Change the direction for the next level
            leftToRight = !leftToRight;

            // Add the current level's result to the final result
            result.push_back(ans);
        }
        return result;
    }
};
