class Solution {
public:
    ListNode* front;
    bool checkPalindrome(ListNode* curr) {
        if (curr == NULL){
            return true;
        }
        bool isPalin = checkPalindrome(curr->next);  // reach the last element
        if(!isPalin){ // this if checks if palindrome cond satisfies or not if it does not satisfies it helps to exit the recursion instead of keep going on.
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