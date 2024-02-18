#include "AllNecessaryHeaders.h"

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int res = 0;
        for (int i = 0; i < words.size() - 1; ++i)
        {
            for (int j = i + 1; j < words.size(); ++j)
            {
                if (isPrefixAndSuffix(words[i], words[j]))
                {
                    ++res;
                }
            }
        }
        return res;
    }

    bool isPrefixAndSuffix(const string &word1, const string &word2)
    {
        return isPrefix(word1, word2) && isSuffix(word1, word2);
    }

    bool isPrefix(const string &word1, const string &word2)
    {
        return word1 == word2.substr(0, word1.size());
    }

    bool isSuffix(const string &word1, const string &word2)
    {
        return word1 == word2.substr(word2.size() - word1.size());
    }
};
