class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fastp = head;
        ListNode* slowp = head;
        for (int i = 0; i < n; i++){
            fastp = fastp->next;
            if (fastp == NULL){
                return head->next;
            }
        }
        while (fastp->next != NULL) {
            fastp = fastp->next;
            slowp = slowp->next;
        }
        ListNode* delNode = slowp->next;
        slowp->next = slowp->next->next;
        delete delNode;
        return head;
    }
};