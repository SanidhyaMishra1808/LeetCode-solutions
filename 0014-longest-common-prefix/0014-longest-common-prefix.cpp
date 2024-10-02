class TrieNode {
public:
    char data;
    TrieNode* children[26];
    int childCount;
    bool isTerminal;

    // Constructor
    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        childCount = 0;
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;
    // Constructor
    Trie() {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, const string& word) {
        // Base case
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        // Assuming word will be lowercase
        int index = word[0] - 'a';
        TrieNode* child;

        // Present
        if (root->children[index] != NULL) {
            child = root->children[index];
        }
        // Absent
        else {
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }

        // Recursion
        insertUtil(child, word.substr(1));
    }

    void insertWord(const string& word) {
        insertUtil(root, word);
    }

    void lcp(const string& str, string& ans) {
        TrieNode* current = root;
        for (int i = 0; i < str.length(); i++) {
            char ch = str[i];
            if (current->childCount == 1) {
                ans.push_back(ch);
                // Move forward
                int index = ch - 'a';
                current = current->children[index];
            } else {
                break;
            }
            if (current->isTerminal) {
                break;
            }
        }
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        Trie* t = new Trie();
        for (int i = 0; i < strs.size(); i++) {
            t->insertWord(strs[i]);
        }

        string first = strs[0];
        string ans = "";
        t->lcp(first, ans);
        return ans;
    }
};