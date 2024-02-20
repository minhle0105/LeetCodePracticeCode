#include "AllNecessaryHeaders.h"

class Solution {
public:
    vector<int> amountPainted(vector<vector<int>>& paint) {
        vector<int> res;
        int max_paint = 0;
        for (const auto &p : paint)
        {
            max_paint = max(max_paint, p[1]);
        }
        vector<int> areas(max_paint, 0);
        for (const auto &pos : paint)
        {
            int index = pos[0];
            int count = 0;
            while (index < pos[1])
            {
                if (areas[index] == 0)
                {
                    areas[index] = pos[1];
                    ++count;
                    ++index;
                }
                else
                {
                    index = areas[index];
                }
            }
            res.push_back(count);
        }
        return res;
    }
};
