class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode* root;

public:
    Trie() { root = new TrieNode('\0'); }

    void insertUtil(TrieNode* root, string word) {
        // base case
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }
        //  assuming word will be capitals
        int index = word[0] - 'a';
        TrieNode* child;
        // present
        if (root->children[index] != NULL) {
            child = root->children[index];
        }
        // absent
        else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        // recursion
        insertUtil(child, word.substr(1));
    }

    void insert(string word) { insertUtil(root, word); }

    bool searchUtil(TrieNode* root, string word) {
        // base case
        if (word.length() == 0) {
            return root->isTerminal;
        }
        int index = word[0] - 'a';
        TrieNode* child;
        // present
        if (root->children[index] != NULL) {
            child = root->children[index];
        }
        // absent
        else {
            return false;
        }
        // recursion
        return searchUtil(child, word.substr(1));
    }

    bool search(string word) { return searchUtil(root, word); }

    bool prefixUtil(TrieNode* root, string word) {
        // base case
        if (word.length() == 0) {
            return true;
        }
        int index = word[0] - 'a';
        TrieNode* child;
        // present
        if (root->children[index] != NULL) {
            child = root->children[index];
        }
        // absent
        else {
            return false;
        }
        // recursion
        return prefixUtil(child, word.substr(1)); // should call prefixUtil
    }

    bool startsWith(string prefix) {
        return prefixUtil(root, prefix);
    }
};