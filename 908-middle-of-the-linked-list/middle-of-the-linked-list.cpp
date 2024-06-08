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
    int getLen(ListNode* head){
        int len = 0;
        while(head != NULL){
            len++;
            head = head -> next;
        }
        return len;
    }
    ListNode* middleNode(ListNode* head) {
        int len = getLen(head);
        int mid = len / 2;
        ListNode* current = head;
        for (int i = 0; i < mid; i++) {
            current = current->next;
        }
        return current;
    }
};