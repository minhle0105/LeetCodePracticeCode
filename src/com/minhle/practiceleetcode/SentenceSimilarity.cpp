#include "AllNecessaryHeaders.h"

class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if (sentence1.size() != sentence2.size())
        {
            return false;
        }
        unordered_map<string, unordered_set<string>> equal_pairs;
        for (int i = 0; i < similarPairs.size(); ++i)
        {
            auto word1 = similarPairs[i].front();
            auto word2 = similarPairs[i].back();
            equal_pairs[word1].insert(word2);
            equal_pairs[word2].insert(word1);
        }

        for (int i = 0; i < sentence1.size(); ++i)
        {
            if (sentence1[i] == sentence2[i])
            {
                continue;
            }
            auto word1 = sentence1[i];
            auto word2 = sentence2[i];
            if ((equal_pairs[word1].find(sentence2[i]) == equal_pairs[word1].end()) ||
                (equal_pairs[word2].find(sentence1[i]) == equal_pairs[word2].end()))
            {
                return false;
            }
        }
        return true;
    }
};
