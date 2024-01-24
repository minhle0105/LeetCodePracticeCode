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
        return search(word, root);
    }
private:
    Node* root;
    static constexpr int ALPHABET_SIZE{26};
    
    bool search(string &word, Node* curr)
    {
        for (int i = 0; i < word.size(); ++i)
        {
            char c = word[i];
            if (c == '.')
            {
                string next_word = word.substr(i + 1, word.size() - i - 1);
                for (int j = 0; j < 26; ++j)
                {
                    if (curr->next[j] != nullptr && search(next_word, curr->next[j]))
                    {
                        return true;
                    }
                }
                return false;
            }
            if (curr->next[c - 'a'] == nullptr)
            {
                return false;
            }
            curr = curr->next[c - 'a'];
        }
        return curr->isEndOfWord;
    }
};

class WordDictionary {
public:
    WordDictionary() {
    }

    void addWord(string word) {
        trie.insert(word);
    }

    bool search(string word) {
        return trie.search(word);
    }
private:
    Trie trie;
};