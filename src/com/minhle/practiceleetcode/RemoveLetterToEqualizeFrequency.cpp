#include "AllNecessaryHeaders.h"

class Solution {
public:
    bool equalFrequency(string word) {
        unordered_map<char, int> counter;
        for (char c : word)
        {
            ++counter[c];
        }
        for (int i = 0; i < word.size(); ++i)
        {
            if (check_counter(counter, word[i]))
            {
                return true;
            }
        }
        return false;
    }

    bool check_counter(unordered_map<char, int> &counter, char skip)
    {
        --counter[skip];
        if (counter[skip] == 0)
        {
            counter.erase(skip);
        }
        int mono_frequency = -1;
        for (const auto &pair : counter)
        {
            if (mono_frequency == -1)
            {
                mono_frequency = pair.second;
            }
            else
            {
                if (pair.second != mono_frequency)
                {
                    ++counter[skip];
                    return false;
                }
            }
        }
        return true;
    }
};
