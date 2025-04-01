class Solution {
public:
    ListNode* reverse(ListNode* head, ListNode* tail){
        ListNode* curr = head; 
        ListNode* prev = NULL;
        ListNode* fwd = NULL;
        while(curr != tail){
            fwd = curr -> next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL){
            return head;
        }
        ListNode* temp = head;
        int count = 0;
        while(temp != NULL && count<k){
            temp = temp -> next;
            count++;
        }
        if(count == k){
            ListNode* newHead = reverse(head, temp);
            head->next = reverseKGroup(temp, k);
            return newHead;
        }
        
        return head;
    }
};