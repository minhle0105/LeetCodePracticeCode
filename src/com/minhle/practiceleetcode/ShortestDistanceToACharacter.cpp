#include "AllNecessaryHeaders.h"

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> res(s.size(), 0);
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == c)
            {
                continue;
            }
            int right = i + 1;
            int left = i - 1;
            int dist_right = INT_MAX;
            int dist_left = INT_MAX;
            while (right < s.size())
            {
                if (s[right] == c)
                {
                    dist_right = abs(right - i);
                    break;
                }
                ++right;
            }
            if (dist_right <= 1)
            {
                res[i] = dist_right;
                continue;
            }
            while (left >= 0)
            {
                if (s[left] == c)
                {
                    dist_left = abs(left - i);
                    break;
                }
                --left;
            }
            res[i] = min(dist_right, dist_left);
        }
        return res;
    }
};
