class Solution {
public:
// length of linked list
    int getLen(ListNode* head){
        int len = 0;
        ListNode* temp = head;
        while(temp != NULL){
            len++;
            temp = temp -> next;
        }
        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = getLen(head);
        int pos = length - n;

        if (pos == 0) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        ListNode* current = head;
        for (int i = 0; i < pos - 1; i++) {
            if(current == NULL){
                return head;
            }
            current = current->next;
        }
        if (current != NULL && current->next != NULL) {
            ListNode* nodeToRemove = current->next;
            current->next = current->next->next;
            delete nodeToRemove;
        }
        return head;
    }
};