#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> counter;
        int res = 0;
        int first = 0;
        int second = 0;
        while (first < s.size())
        {
            ++counter[s.at(first)];
            while (second < s.size() && counter.size() > 2)
            {
                --counter[s.at(second)];
                if (counter[s.at(second)] == 0)
                {
                    counter.erase(s.at(second));
                }
                ++second;
            }
            ++first;
            res = max(res, first - second);
        }
        return res;
    }
};
