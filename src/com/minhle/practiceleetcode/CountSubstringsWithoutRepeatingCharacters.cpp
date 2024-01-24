#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numberOfSpecialSubstrings(string s) {
        int res = 0;
        int first = 0;
        int second = 0;
        unordered_map<char, int> counter;
        while (first < s.size())
        {
            ++counter[s.at(first)];
            while (second < s.size() && counter[s.at(first)] > 1)
            {
                --counter[s.at(second)];
                if (counter[s.at(second)] == 0)
                {
                    counter.erase(s.at(second));
                }
                ++second;
            }
            ++first;
            res += (first - second);
        }
        return res;
    }
};
