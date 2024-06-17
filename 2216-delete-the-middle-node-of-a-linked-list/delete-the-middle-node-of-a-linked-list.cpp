class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head-> next == NULL){
            head = NULL;
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = head;
        while(fast != NULL && fast->next != NULL){
            temp = slow;     //stores the value of slow which will point middle
            slow = slow->next;
            fast = fast->next->next;
        }
        temp-> next = slow-> next;
        slow = NULL;
        return head;
    }
};