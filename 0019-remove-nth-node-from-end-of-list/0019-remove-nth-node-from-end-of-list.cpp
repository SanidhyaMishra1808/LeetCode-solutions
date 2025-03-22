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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fwd = head;
        ListNode* bck = head;

        // ab me fwd node ko normal node se nth step aage rakhung jis se jab mera fwd node NULL reach karega tab mera bck node us position pe hoga jo mujhe delete karni hogi
        for(int i=0; i<n; i++){
            fwd = fwd -> next;
            if(fwd == NULL){
                return head->next;
            }
        }
        while(fwd->next != NULL){
            fwd = fwd ->next;
            bck = bck ->next;
        }
        ListNode* delNode = bck->next;
        bck->next = bck->next->next;
        delete delNode;
        return head;
    }
};