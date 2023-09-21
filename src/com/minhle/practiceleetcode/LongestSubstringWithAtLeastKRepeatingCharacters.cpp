#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        int res = 0;
        for (int i = 1; i <= 26; ++i)
        {
            int first_pointer = 0;
            int second_pointer = 0;
            unordered_map<char, int> counter;
            while (first_pointer < s.size())
            {
                if (counter.find(s.at(first_pointer)) == counter.end())
                {
                    counter[s.at(first_pointer)] = 0;
                }
                ++counter[s.at(first_pointer)];
                ++first_pointer;
                while (second_pointer < s.size() && counter.size() > i)
                {
                    --counter[s.at(second_pointer)];
                    if (counter[s.at(second_pointer)] == 0)
                    {
                        counter.erase(counter.find(s.at(second_pointer)));
                    }
                    ++second_pointer;
                }
                bool valid = true;
                for (const auto &pair : counter)
                {
                    if (pair.second < k)
                    {
                        valid = false;
                        break;
                    }
                }
                if (valid)
                {
                    res = max(res, first_pointer - second_pointer);
                }
            }
        }
        return res;
    }
};
