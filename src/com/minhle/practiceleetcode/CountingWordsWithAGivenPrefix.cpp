#include "AllNecessaryHeaders.h"

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int res = 0;
        for (auto &word : words)
        {
            if (has_prefix(word, pref))
            {
                ++res;
            }
        }
        return res;
    }

    bool has_prefix(string &word, string &prefix)
    {
        if (word.size() < prefix.size())
        {
            return false;
        }
        if (word.size() == prefix.size())
        {
            return word == prefix;
        }

        int word_pos = 0;
        int prefix_pos = 0;
        while (prefix_pos < prefix.size())
        {
            if (word[word_pos] != prefix[prefix_pos])
            {
                return false;
            }
            ++word_pos;
            ++prefix_pos;
        }
        return true;
    }
};
