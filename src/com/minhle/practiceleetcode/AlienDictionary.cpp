#include <unordered_map>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, vector<char>> graph;
        unordered_map<char, int> degrees;
        for (const string &word : words)
        {
            for (char c : word)
            {
                degrees[c] = 0;
            }
        }
        for (int i = 0; i < words.size() - 1; ++i)
        {
            string word_1 = words.at(i);
            string word_2 = words.at(i + 1);
            bool changed = false;
            for (int j = 0; j < min(word_1.size(), word_2.size()); ++j)
            {
                if (word_1.size() > word_2.size())
                {
                    if (isPrefixOf(word_1, word_2))
                    {
                        return "";
                    }
                }
                if (word_1.at(j) != word_2.at(j))
                {
                    graph[word_1.at(j)].push_back(word_2.at(j));
                    ++degrees[word_2.at(j)];
                    changed = true;
                    break;
                }   
            }
        }
        queue<char> q;
        string res;

        for (const auto &pair : degrees)
        {
            if (pair.second == 0)
            {
                q.push(pair.first);
            }
        }

        while (!q.empty())
        {
            char curr = q.front();
            q.pop();
            res += curr;

            for (char neighbor : graph[curr])
            {
                --degrees[neighbor];
                if (degrees[neighbor] == 0)
                {
                    q.push(neighbor);
                }
            }
        }
        return res.size() < degrees.size() ? "" : res;
    }

    bool isPrefixOf(string &word, string &prefix)
    {
        if (prefix.size() == 0)
        {
            return true;
        }
        if (prefix.front() == word.front())
        {
            word.erase(word.begin());
            prefix.erase(prefix.begin());
            return isPrefixOf(word, prefix);
        }
        return false;
    }
};
