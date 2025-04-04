class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        // Step 1: Create a dummy node with a high value.
        // This dummy node acts as the starting point of the new sorted list.
        ListNode* dummy = new ListNode(1000); // ek extra list bna lo (dummy head)

        // Step 2: Traverse through the original list
        while (head) {
            // Store the next node, because we’ll be changing head->next soon
            ListNode* next = head->next;  // head ke agle node ko store karo (link tootne se bachane ke liye)

            // Start from the dummy node each time to find the correct position
            ListNode* temp = dummy;

            // Step 3: Find the correct position to insert the current node in the sorted part
            while (temp->next && temp->next->val < head->val) {
                temp = temp->next;  // jab tak sorted part ka value chhota hai, aage badhte jao
            }

            // Step 4: Insert the current node between temp and temp->next
            head->next = temp->next; // head ka next ab temp ke baad aane wala hoga
            temp->next = head;       // temp ke baad ab head insert karo

            // Step 5: Move to the next node in the original list
            head = next;  // original list ka next node process karo
        }

        // Return the new sorted list (dummy->next points to the actual head)
        return dummy->next;
    }
};
