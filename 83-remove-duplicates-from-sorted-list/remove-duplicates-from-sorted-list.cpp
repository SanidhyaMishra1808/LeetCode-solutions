class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head ->next == NULL){
            return head; 
        }
        ListNode* curr = head;
        while(curr != NULL && curr -> next != NULL){
            if(curr -> val == curr -> next -> val){
                ListNode* forward = curr -> next -> next;
                ListNode* toDel = curr -> next;
                delete(toDel);
                curr -> next = forward; 
            }else{
                curr = curr -> next;
            }
        }
        return head;
    }
};