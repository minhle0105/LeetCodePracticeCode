#include "AllNecessaryHeaders.h"

class Solution {
public:
    int res;
    int maxLength(vector<string>& arr) {
        res = 0;
        string current_word;

        for (int i = 0; i < arr.size(); ++i)
        {
            if (!contains_unique_char(arr[i]))
            {
                continue;
            }
            current_word = arr[i];
            backtracking(arr, i, current_word);
        }
        return res;
    }

    void backtracking(const vector<string> &words, int index, string &current_word)
    {
        res = max(res, static_cast<int>(current_word.size()));
        for (int i = index + 1; i < words.size(); ++i)
        {
            auto temp = current_word;
            current_word += words[i];
            if (contains_unique_char(current_word))
            {
                backtracking(words, i, current_word);
            }
            current_word = temp;
        }
    }

    bool contains_unique_char(const string &word)
    {
        unordered_set<char> counter;
        for (char c : word)
        {
            counter.insert(c);
        }
        return counter.size() == word.size();
    }
};
