#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> counter;
        int nDistinct = 0;
        int first_pointer = 0;
        int second_pointer = 0;
        int res = 0;
        while (first_pointer < s.size())
        {
            if (counter.find(s.at(first_pointer)) == counter.end() || counter[s.at(first_pointer)] == 0)
            {
                counter[s.at(first_pointer)] = 1;
                ++nDistinct;
            }
            else
            {
                ++counter[s.at(first_pointer)];
            }
            ++first_pointer;
            while (second_pointer < s.size() && nDistinct > k)
            {
                if (counter[s.at(second_pointer)] == 1)
                {
                    --nDistinct;
                }
                --counter[s.at(second_pointer)];
                ++second_pointer;
            }
            res = max(res, first_pointer - second_pointer);
        }
        return res;
    }
};
