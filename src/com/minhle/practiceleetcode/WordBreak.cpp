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

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        root = new Node();
        for (const auto &word : wordDict)
        {
            insert(word);
        }
        vector<bool> dp(s.size() + 1, false);
        dp.back() = true; // last empty is true
        for (int i = s.size() - 1; i >= 0; --i)
        {
            auto curr = root;
            for (int j = i; j < s.size(); ++j)
            {
                if (curr->next[s[j] - 'a'] == nullptr)
                {
                    break;
                }
                curr = curr->next[s[j] - 'a'];
                if (curr->isEndOfWord)
                {
                    dp[i] = dp[j + 1]|| dp[i];
                }
            }
        }
        return dp.front();
    }
private:
    Node* root;

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
};
