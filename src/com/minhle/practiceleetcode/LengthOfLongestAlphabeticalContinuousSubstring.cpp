#include <string>

using namespace std;

class Solution {
public:
    int longestContinuousSubstring(string s) {
        int res = 0;
        int i = 0;
        while (i < s.length())
        {
            int j = i + 1;
            while (j < s.length() && (s[j] - s[j - 1] == 1))
            {
                ++j;
            }
            res = max(res, j - i);
            i = j;
        }
        return res;
    }
};

