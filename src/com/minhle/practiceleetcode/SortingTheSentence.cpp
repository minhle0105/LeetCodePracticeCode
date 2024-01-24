#include "AllNecessaryHeaders.h"

class Solution {
public:
    string sortSentence(string s) {
        vector<string> sentence(9, "");
        auto s_split = split(s);
        for (const auto &word : s_split)
        {
            auto data = process_word(word);
            sentence[data.second - 1] = data.first;
        }
        string res;
        for (const auto &word : sentence)
        {
            if (word.empty())
            {
                break;
            }
            res += word;
            res += " ";
        }
        res.pop_back();
        return res;
    }

private:
    pair<string, int> process_word(const string &word)
    {
        pair<string, int> res;
        int digit_index = 0;
        for (int i = 0; i < word.size(); ++i)
        {
            if (isdigit(word[i]))
            {
                digit_index = i;
                break;
            }
        }
        res.first = word.substr(0, digit_index);
        res.second = stoi(word.substr(digit_index, word.size() - digit_index));
        return res;
    }

    vector<string> split(const string &s)
    {
        vector<string> res;
        int left = 0;
        while (left < s.size())
        {
            int right = left + 1;
            string word;
            word += s[left];
            while (right < s.size() && s[right] != ' ')
            {
                word += s[right];
                ++right;
            }
            res.push_back(word);
            left = right + 1;
        }
        return res;
    }
};
