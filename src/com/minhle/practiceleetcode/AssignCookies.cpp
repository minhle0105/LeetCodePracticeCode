#include "AllNecessaryHeaders.h"

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int res = 0;
        int anchor = 0;
        for (int i = 0; i < g.size(); ++i)
        {
            for (int j = anchor; j < s.size(); ++j)
            {
                if (s[j] >= g[i])
                {
                    ++res;
                    anchor = j + 1;
                    break;
                }
            }
        }
        return res;
    }
};
