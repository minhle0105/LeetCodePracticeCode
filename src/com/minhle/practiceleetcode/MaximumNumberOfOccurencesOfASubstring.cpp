#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        left = minSize;
        right = maxSize;
        int res = 0;
        unordered_map<char, int> counter;
        unordered_map<string, int> res_map;
        int first = 0;
        int second = 0;
        while (first < s.size())
        {
            if (counter.find(s.at(first)) == counter.end())
            {
                counter[s.at(first)] = 0;
            }
            ++counter[s.at(first)];
            ++first;
            while (second < s.size() && counter.size() > maxLetters)
            {
                --counter[s.at(second)];
                if (counter[s.at(second)] == 0)
                {
                    counter.erase(counter.find(s.at(second)));
                }
                ++second;
            }
            int curr = second;
            while (curr < first)
            {
                if (inRange(first - curr))
                {
                    string window = s.substr(curr, first - curr);
                    if (res_map.find(window) == res_map.end())
                    {
                        res_map[window] = 0;
                    }
                    ++res_map[window];
                }
                ++curr;
            }
        }
        for (const auto &pair : res_map)
        {
            res = max(res, pair.second);
        }
        return res;
    }

    bool inRange(int size)
    {
        return left <= size && size <= right;
    }

private:
    int left;
    int right;
};