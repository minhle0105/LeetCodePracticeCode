#include "AllNecessaryHeaders.h"

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> res;
        if (words.size() == 1)
        {
            for (char c : words.front())
            {
                res.push_back(string{c});
            }
            return res;
        }
        queue<string> q;
        for (const auto &word : words)
        {
            q.push(word);
        }
        while (q.size() > 1)
        {
            auto word1 = q.front();
            q.pop();
            auto word2 = q.front();
            q.pop();
            string common = get_common_chars(word1, word2);
            q.push(common);
        }
        string final_word = q.front();
        for (char c : final_word)
        {
            res.push_back(string{c});
        }
        return res;
    }

    string get_common_chars(const string &word1, const string &word2)
    {
        unordered_map<char, int> counter1;
        unordered_map<char, int> counter2;
        for (char c : word1)
        {
            ++counter1[c];
        }
        for (char c : word2)
        {
            ++counter2[c];
        }
        string res;
        for (const auto &pair : counter1)
        {
            if (counter2.find(pair.first) != counter2.end())
            {
                string common(min(pair.second, counter2[pair.first]), pair.first);
                res += common;
            }
        }
        return res;
    }
};
