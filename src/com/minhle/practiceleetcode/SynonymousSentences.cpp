#include "AllNecessaryHeaders.h"

class Solution {
public:
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        group_synonyms.clear();
        synonym_to_id.clear();
        next_id = 0;

        for (const auto &pair : synonyms)
        {
            union_words(pair.front(), pair.back());
        }
        vector<string> res;
        auto words = split(text);
        vector<int> positions_to_replaced;
        for (int i = 0; i < words.size(); ++i)
        {
            if (synonym_to_id.find(words[i]) != synonym_to_id.end())
            {
                positions_to_replaced.push_back(i);
            }
        }

        vector<string> replaced(words.begin(), words.end());
        for (int position : positions_to_replaced)
        {
            replaced[position] = SIGN;
        }
        recursively_fill(words, replaced, res, positions_to_replaced, 0);
        sort(res.begin(), res.end(), [](const string &a, const string &b)
        {
            return a < b;
        });
        return res;
    }
private:
    const string SIGN{"*****"};
    int next_id;
    unordered_map<int, unordered_set<string>> group_synonyms;
    unordered_map<string, int> synonym_to_id;

    void union_words(const string &word_a, const string &word_b)
    {
        if (synonym_to_id.find(word_a) == synonym_to_id.end() && synonym_to_id.find(word_b) == synonym_to_id.end())
        {
            synonym_to_id[word_a] = next_id;
            synonym_to_id[word_b] = next_id;
            group_synonyms[next_id].insert(word_a);
            group_synonyms[next_id].insert(word_b);
            ++next_id;
        }
        else if (synonym_to_id.find(word_a) != synonym_to_id.end() && synonym_to_id.find(word_b) != synonym_to_id.end())
        {
            int id_a = synonym_to_id[word_a];
            int id_b = synonym_to_id[word_b];
            auto set_a = group_synonyms[id_a];
            auto set_b = group_synonyms[id_b];

            if (set_a.size() < set_b.size())
            {
                for (const auto &string : group_synonyms[id_a])
                {
                    group_synonyms[id_b].insert(string);
                    synonym_to_id[string] = id_b;
                }
                group_synonyms[id_a].clear();
            }
            else
            {
                for (const auto &string : group_synonyms[id_b])
                {
                    group_synonyms[id_a].insert(string);
                    synonym_to_id[string] = id_a;
                }
                group_synonyms[id_b].clear();
            }
        }
        else
        {
            if (synonym_to_id.find(word_a) == synonym_to_id.end())
            {
                int id = synonym_to_id[word_b];
                synonym_to_id[word_a] = id;
                group_synonyms[id].insert(word_a);
            }
            else
            {
                int id = synonym_to_id[word_a];
                synonym_to_id[word_b] = id;
                group_synonyms[id].insert(word_b);
            }
        }
    }

    void recursively_fill(const vector<string> &original_text, vector<string> &replaced, vector<string> &res,
                          vector<int> &positions, int index)
    {
        if (index == positions.size())
        {
            string replaced_sentence;
            for (const auto &word : replaced)
            {
                replaced_sentence += (word + " ");
            }
            replaced_sentence.pop_back();
            res.push_back(replaced_sentence);
            return;
        }

        int position = positions[index];
        const auto &original_word = original_text[position];
        int group_id = synonym_to_id[original_word];
        for (const auto &synonym : group_synonyms[group_id])
        {
            replaced[position] = synonym;
            recursively_fill(original_text, replaced, res, positions, index + 1);
            replaced[position] = SIGN;
        }
    }

    vector<string> split(const string &text)
    {
        vector<string> res;
        int i = 0;
        while (i < text.size())
        {
            int j = i + 1;
            while (j < text.size() && text[j] != ' ')
            {
                ++j;
            }
            res.push_back(text.substr(i, j - i));
            i = j + 1;
        }
        return res;
    }
};
