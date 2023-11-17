#include "AllNecessaryHeaders.h"

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int anchor = 0;
        bool ch_exists = false;
        for (int i = 0; i < word.size(); ++i)
        {
            if (word[i] == ch)
            {
                anchor = i;
                ch_exists = true;
                break;
            }
        }
        if (!ch_exists)
        {
            return word;
        }
        int right = anchor;
        int left = 0;
        while (left <= anchor / 2)
        {
            char temp = word[left];
            word[left] = word[right];
            word[right] = temp;
            ++left;
            --right;
        }
        return word;
    }
};
