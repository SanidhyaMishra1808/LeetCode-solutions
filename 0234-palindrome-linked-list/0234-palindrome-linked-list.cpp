class Solution {
public:
    ListNode* front;
    bool checkPalindrome(ListNode* curr) {
        if (curr == NULL){
            return true;
        }
        bool isPalin = checkPalindrome(curr->next);
        if(!isPalin){
            return false;
        }
        if(front->val != curr->val){
            return false;
        }
        front = front->next;
        return isPalin;
    }
    bool isPalindrome(ListNode* head) {
        front = head;
        return checkPalindrome(head);
    }
};
