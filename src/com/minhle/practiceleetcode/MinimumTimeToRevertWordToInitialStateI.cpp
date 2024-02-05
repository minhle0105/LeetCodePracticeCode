#include "AllNecessaryHeaders.h"

class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int count = 0;
        string curr = word;
        while (true)
        {
            curr = curr.substr(k) + string(k, '*');
            ++count;
            if (isIdentical(word, curr))
            {
                return count;
            }
        }
        return count;
    }
    
    bool isIdentical(const string &word, const string &curr)
    {
        for (int i = 0; i < word.size(); ++i)
        {
            if (curr[i] != '*' && word[i] != curr[i])
            {
                return false;
            }
        }
        return true;
    }
};
