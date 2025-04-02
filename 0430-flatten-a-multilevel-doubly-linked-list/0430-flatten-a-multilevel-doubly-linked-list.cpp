/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) {
            return NULL;
        }
        Node* curr = head;
        stack<Node*> stk; 
        while (curr) {
            if (curr->child) {
                if (curr->next) stk.push(curr->next);
                curr->next = curr->child;
                curr->next->prev = curr;
                curr->child = NULL; 
            }
            if (!curr->next && !stk.empty()) {
                curr->next = stk.top();
                stk.top()->prev = curr;
                stk.pop();
            }
            curr = curr->next;
        }
        return head;
    }
};