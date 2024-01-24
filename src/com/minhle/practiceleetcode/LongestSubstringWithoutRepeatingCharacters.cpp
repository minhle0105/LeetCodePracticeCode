#include <set>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> set;
        int left_pointer = 0;
        int right_pointer = 0;
        int res = 0;
        while (right_pointer < s.size())
        {
            while (set.find(s[right_pointer]) != set.end())
            {
                set.erase(s[left_pointer]);
                ++left_pointer;
            }
            set.insert(s[right_pointer]);
            ++right_pointer;
            res = max(res, right_pointer - left_pointer);
        }
        return res;
    }
};
