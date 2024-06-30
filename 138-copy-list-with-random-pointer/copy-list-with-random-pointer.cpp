class Solution {
private:
    void insertAtTail(Node*& head, Node*& tail, int val) {
        Node* newnode = new Node(val);
        if (head == NULL) {
            head = newnode;
            tail = newnode;
            return;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
    }

public:
    Node* copyRandomList(Node* head) {
        // Step 1: Creating a clone list
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        Node* temp = head;
        while (temp != NULL) {
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp = temp->next;
        }
        // Step 2: Creating a map named oldToNew
        unordered_map<Node*, Node*> oldToNew;
        temp = head;
        Node* temp2 = cloneHead;
        while (temp != NULL && temp2 != NULL) {
            oldToNew[temp] = temp2;
            temp = temp->next;
            temp2 = temp2->next;
        }
        // Step 3: Updating the random pointers in the clone list
        temp = head;
        temp2 = cloneHead;
        while (temp != NULL) {
            temp2->random = oldToNew[temp->random];
            temp = temp->next;
            temp2 = temp2->next;
        }
        return cloneHead;
    }
};
