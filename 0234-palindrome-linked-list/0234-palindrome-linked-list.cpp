#include<vector>
class Solution {
private:
bool isPalindrome(vector<int>&arr){
    int s = 0;
    int n = arr.size();
    int e = n-1;
    while(s<e){
        if(arr[s] != arr[e]){
            return false;
        }
        s++;
        e--;
    }
    return true;
}
public:
// ListNode* reverse(ListNode* head) {
//     if(head == NULL || head -> next == NULL){
//             return head;
//         }
//         ListNode* curr = head;
//         ListNode* forward = NULL;
//         ListNode* prev = NULL;
//         while(curr != NULL){
//             forward = curr -> next;
//             curr -> next = prev;
//             prev = curr;
//             curr = forward;
//         }
//         return prev;
// }
    bool isPalindrome(ListNode* head) {
        // ListNode* slow = head;
        // ListNode* fast = head;
        // while(fast -> next != NULL && fast -> next -> next != NULL){
        //     slow = slow -> next;
        //     fast = fast -> next -> next;
        // }
        // ListNode* secondHalf = reverse(slow->next);
        // ListNode* firstHalf = head;
        // ListNode* secondHalfCopy = secondHalf;
        // while (secondHalf != NULL) {
        //     if (firstHalf->val != secondHalf->val) {
        //         reverse(secondHalfCopy);
        //         return false;
        //     }
        //     firstHalf = firstHalf->next;
        //     secondHalf = secondHalf->next;
        // }
        // reverse(secondHalfCopy);
        // return true;
        vector<int>arr;
        ListNode* temp = head;
        while(temp != NULL){
            arr.push_back(temp -> val);
            temp = temp -> next;
        }
        return isPalindrome(arr);
    }
};