class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        // tortoise and haire method
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};