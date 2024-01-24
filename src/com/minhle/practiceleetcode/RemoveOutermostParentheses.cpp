#include <utility>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        pair<int, int> counts;
        vector<int> valid(s.size(), 1);
        int start = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
            {
                ++counts.first;
            }
            else
            {
                ++counts.second;
            }
            if (counts.first == counts.second)
            {
                valid[start] = 0;
                valid[i] = 0;
                start = i + 1;
                counts.first = 0;
                counts.second = 0;
            }
        }
        string res;
        for (int i = 0; i < s.size(); ++i)
        {
            if (valid[i] == 1)
            {
                res += s[i];
            }
        }
        return res;
    }
};
