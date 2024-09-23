struct Compare{
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
    int n=lists.size();
    if(n==0){ 
        return NULL;
    }

    for(int i=0;i<n;i++){
        if(lists[i]!=NULL){
            pq.push(lists[i]);
        }
    }

    ListNode* dummy=new ListNode;
    ListNode* ans=dummy;

    while(!pq.empty()){
        auto x=pq.top();
        pq.pop();
        ListNode* node= x;
        ans->next=node;
        ans=ans->next;
        if(node->next!=NULL) {
            pq.push({node->next});
        }
    }
    return dummy->next;
    }
};