struct Node {
    Node * links[2];
    bool isSet(int bit){
        return (links[bit] != NULL);
    }
    Node* get(int bit){
        return links[bit];
    }
    void put(int bit,Node * node){
        links[bit] = node;
    }
};

class Tries{
private:
    Node * root;
public:
    Tries(){
        root = new Node();
    }
    void insert(int num){
        Node * node = root;
        for(int i=31; i>=0; i--){
            int bit = (num >> i) & 1;
            if(!node->isSet(bit)){
                node->put(bit,new Node());
            }
            node = node->get(bit);
        }
    }
    int getMax(int num){
        Node * node = root;
        int maxi=0;
        for(int i=31; i>=0; i--){
            int bit = (num >> i) & 1;
            if(node->isSet(1-bit)){
                maxi |= (1<<i);
                node = node->get(1-bit);
            }else{
                node=node->get(bit);
            }

        }
        return maxi;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Tries* trie = new Tries();
        int n=nums.size(),res=0;
        for(int i=n-1; i>=0; i--){
            trie->insert(nums[i]);
            res = max(res,trie->getMax(nums[i]));         
        }
        return res;
    }
};