#include "AllNecessaryHeaders.h"

struct Node
{
    bool isEndOfWord;
    vector<Node*> next;

    Node()
    {
        isEndOfWord = false;
        next = vector<Node*>(26, nullptr);
    }
};

class Trie {
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        auto curr = root;
        for (char c : word)
        {
            if (curr->next[c - 'a'] == nullptr)
            {
                curr->next[c - 'a'] = new Node();
            }
            curr = curr->next[c - 'a'];
        }
        curr->isEndOfWord = true;
    }
    
    bool search(string word) {
        auto curr = root;
        for (char c : word)
        {
            if (curr->next[c - 'a'] == nullptr)
            {
                return false;
            }
            curr = curr->next[c - 'a'];
        }
        return curr->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        auto curr = root;
        for (char c : prefix)
        {
            if (curr->next[c - 'a'] == nullptr)
            {
                return false;
            }
            curr = curr->next[c - 'a'];
        }
        return true;
    }
private:
    Node* root;
};
