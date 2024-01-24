#include "AllNecessaryHeaders.h"

// bool knows(int a, int b) is a given API

class Solution {
public:
    int findCelebrity(int n) {
        vector<int> can_be_celeb(n, true);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == j)
                {
                    continue;
                }
                if (can_be_celeb[i] && (knows(i, j) || !knows(j, i)))
                {
                    can_be_celeb[i] = false;
                }
            }
        }

        for (int i = 0; i < n; ++i)
        {
            if (can_be_celeb[i])
            {
                return i;
            }
        }
        return -1;
    }
};
