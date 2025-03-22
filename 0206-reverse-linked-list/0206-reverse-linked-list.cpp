/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void solution(ListNode*& head, ListNode* curr, ListNode* prev) {
        if (curr == NULL) {
            head = prev;
            return;
        }
        ListNode* fwd = curr->next;
        solution(head, fwd, curr);
        curr->next = prev;
    }

    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;
        solution(head, curr, prev);
        return head;
    }
};