class Solution {
public:
ListNode* reverse(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head; 
    }
    ListNode* newHead = reverse(head->next);
    ListNode* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast -> next != NULL && fast -> next -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode* secondHalf = reverse(slow->next);
        ListNode* firstHalf = head;
        ListNode* secondHalfCopy = secondHalf;

        while (secondHalf != NULL) {
            if (firstHalf->val != secondHalf->val) {
                reverse(secondHalfCopy);
                return false;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        reverse(secondHalfCopy);
        return true;
    }
};