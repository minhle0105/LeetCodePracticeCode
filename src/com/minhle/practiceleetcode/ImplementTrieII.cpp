#include "AllNecessaryHeaders.h"

class Node
{
public:
    bool isEndOfWord;
    int countWord;
    int countPrefix;
    vector<Node*> next;

    Node() : isEndOfWord(false), countWord(0), countPrefix(0)
    {
        next = vector<Node*>(26, nullptr);
    }
};

class Trie {
public:
    Trie() {
        root = new Node();
        char ch = 'a';
        for (int i = 0; i < 26; ++i)
        {
            char_pos[i] = ch;
            ++ch;
        }
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
            ++curr->countPrefix;
        }
        curr->isEndOfWord = true;
        ++curr->countWord;
    }

    int countWordsEqualTo(string word) {
        auto curr = root;
        for (char c : word)
        {
            if (curr->next[c - 'a'] == nullptr)
            {
                return 0;
            }
            curr = curr->next[c - 'a'];
        }
        return curr->countWord;
    }

    int countWordsStartingWith(string prefix) {
        auto curr = root;
        string word;
        for (char c : prefix)
        {
            if (curr->next[c - 'a'] == nullptr)
            {
                break;
            }
            curr = curr->next[c - 'a'];
            word += char_pos[c - 'a'];
        }
        return word.size() >= prefix.size() ? curr->countPrefix : 0;
    }

    void erase(string word) {
        auto curr = root;
        for (char c : word)
        {
            curr = curr->next[c - 'a'];
            --curr->countPrefix;
        }
        if (curr->isEndOfWord)
        {
            --curr->countWord;
        }
    }
private:
    Node* root;
    map<int, char> char_pos;
};