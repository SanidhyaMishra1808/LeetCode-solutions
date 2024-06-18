class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even; // Store the start of the even list
        
        while(even != NULL && even->next != NULL){
            odd->next = odd->next->next;
            odd = odd->next;
            even->next = even->next->next;
            even = even->next;
        }
        
        // Connect the end of the odd list to the start of the even list
        odd->next = evenHead;
        return head;
    }
};
