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

class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string &word1, const string &word2){
            return word1.size() > word2.size();
        });
        Trie trie;
        for (const auto &word : words)
        {
            trie.insert(word);
        }
        vector<string> candidates;
        int max_length = 0;
        for (const auto &word : words)
        {
            if (word.size() < max_length)
            {
                break;
            }
            string word_clone = word;
            while (!word_clone.empty())
            {
                if (!trie.search(word_clone))
                {
                    break;
                }
                word_clone.pop_back();
            }
            if (word_clone.empty())
            {
                candidates.push_back(word);
                max_length = word.size();
            }
        }
        sort(candidates.begin(), candidates.end());
        for (const auto &candidate : candidates)
        {
            if (candidate.size() == max_length)
            {
                return candidate;
            }
        }
        return "";
    }
};
