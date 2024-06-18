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
    ListNode* oddEvenList(ListNode* head) {
        //the question is about indices not values
        if(head == NULL || head -> next == NULL){
            return head;
        }
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* temp = even;   // Store the start of the even list
        while(even != NULL && even->next != NULL){
            odd -> next = odd -> next -> next;
            odd = odd->next;
            even -> next = even -> next -> next;
            even = even->next;
        }
        // Connect the end of the odd list to the start of the even list
        odd -> next = temp;
        return head;
    }
};