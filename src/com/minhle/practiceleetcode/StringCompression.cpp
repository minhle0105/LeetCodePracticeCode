#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        size_t i = 0;
        vector<char> res;

        while (i < chars.size())
        {
            char ch = chars.at(i);
            res.push_back(ch);
            int count_ch = 1;
            int j = i + 1;
            while (j < chars.size() && chars.at(j) == ch)
            {
                ++j;
                ++count_ch;
            }
            if (count_ch == 1)
            {
                i = j;
                continue;
            }
            for (char digit : to_string(count_ch))
            {
                res.push_back(digit);
            }
            i = j;
        }
        chars.clear();
        chars = res;
        return res.size();
    }
};
