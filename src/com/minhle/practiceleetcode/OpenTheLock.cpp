#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead_ends;
        if (original == target)
        {
            return 0;
        }
        for (const auto &end : deadends)
        {
            if (end == original || end == target)
            {
                return -1;
            }
            dead_ends.insert(end);
        }
        queue<string> q;
        unordered_set<string> visited;
        unordered_map<string, int> levels;
        levels[original] = 0;
        q.push(original);
        visited.insert(original);

        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i)
            {
                auto inc = construct_next_password_increment(curr, i);
                if (visited.find(inc) == visited.end() && dead_ends.find(inc) == dead_ends.end())
                {
                    visited.insert(inc);
                    q.push(inc);
                    levels[inc] = levels[curr] + 1;
                    if (inc == target)
                    {
                        return levels[inc];
                    }
                }

                auto dec = construct_next_password_decrement(curr, i);
                if (visited.find(dec) == visited.end() && dead_ends.find(dec) == dead_ends.end())
                {
                    visited.insert(dec);
                    q.push(dec);
                    levels[dec] = levels[curr] + 1;
                    if (dec == target)
                    {
                        return levels[dec];
                    }
                }
            }
        }
        return -1;
    }

private:
    const string original = "0000";

    static string construct_next_password_increment(string &curr, int i)
    {
        string next = curr;
        if (next[i] == '9')
        {
            next[i] = '0';
        } else
        {
            next[i] = next[i] + 1;
        }
        return next;
    }
    static string construct_next_password_decrement(string &curr, int i)
    {
        string next = curr;
        if (next[i] == '0')
        {
            next[i] = '9';
        } else
        {
            next[i] = next[i] - 1;
        }
        return next;
    }
};
