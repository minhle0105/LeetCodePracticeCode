#include "AllNecessaryHeaders.h"

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> max_heap;

        for (int i = 0; i < heights.size() - 1; ++i)
        {
            int diff = heights[i + 1] - heights[i];
            if (diff <= 0)
            {
                continue;
            }
            max_heap.push(diff);
            bricks -= diff;
            if (bricks < 0)
            {
                if (ladders == 0)
                {
                    return i;
                }
                int max_diff_so_far = max_heap.top();
                max_heap.pop();
                bricks += max_diff_so_far;
                --ladders;
            }
        }
        return heights.size() - 1;
    }
};
