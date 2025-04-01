class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* curr = head;
        int ans = 0;
        while( curr != NULL){
            ans = ans * 2 + curr->val;
            curr = curr -> next;
        }
        return ans;
    }
};