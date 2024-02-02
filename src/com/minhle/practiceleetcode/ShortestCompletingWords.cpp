#include "AllNecessaryHeaders.h"

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        auto main_counter = count(licensePlate);
        vector<pair<int, string>> completingWords;
        for (int i = 0; i < words.size(); ++i)
        {
            auto word = words[i];
            bool completed = true;
            auto word_counter = count(word);
            for (const auto &pair : main_counter)
            {
                if (word_counter.find(pair.first) == word_counter.end())
                {
                    completed = false;
                    break;
                }
                if (word_counter[pair.first] < pair.second)
                {
                    completed = false;
                    break;
                }
            }
            if (completed)
            {
                completingWords.push_back({i, word});
            }
        }
        sort(completingWords.begin(), completingWords.end(), [](const pair<int, string> &p1, const pair<int, string> &p2){
            if (p1.second.size() == p2.second.size())
            {
                return p1.first < p2.first;
            }
            return p1.second.size() < p2.second.size();
        });
        return completingWords.front().second;
    }

    unordered_map<char, int> count(const string &word)
    {
        unordered_map<char, int> counter;
        for (char c : word)
        {
            if (isdigit(c) || c == ' ')
            {
                continue;
            }
            ++counter[tolower(c)];
        }
        return counter;
    }
};
