#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int window_size = p.size();
        unordered_map<char, int> p_counter;
        for (char c : p)
        {
            if (p_counter.find(c) == p_counter.end())
            {
                p_counter[c] = 0;
            }
            ++p_counter[c];
        }
        unordered_map<char, int> s_counter;
        vector<int> res;
        for (int i = 0; i + window_size <= s.size();)
        {
            int end_window = i + window_size - 1;
            if (s_counter.empty())
            {
                for (int j = i; j <= end_window; ++j)
                {
                    if (s_counter.find(s.at(j)) == s_counter.end())
                    {
                        s_counter[s.at(j)] = 0;
                    }
                    ++s_counter[s.at(j)];
                }
            }
            else
            {
                if (p_counter.find(s.at(end_window)) == p_counter.end())
                {
                    i = end_window + 1;
                    s_counter.clear();
                    continue;
                }
                if (s_counter.find(s.at(end_window)) == s_counter.end())
                {
                    s_counter[s.at(end_window)] = 0;
                }
                ++s_counter[s.at(end_window)];
                --s_counter[s.at(i - 1)];
                if (s_counter[s.at(i - 1)] == 0)
                {
                    s_counter.erase(s_counter.find(s.at(i - 1)));
                }
            }
            bool isAnagram = true;
            for (const auto &pair : s_counter)
            {
                if (pair.second != p_counter[pair.first])
                {
                    isAnagram = false;
                    break;
                }
            }
            if (isAnagram)
            {
                res.push_back(i);
            }
            ++i;
        }
        return res;
    }
};
