class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int even_position = 0;
        int odd_position = 0;
        for (int p : position)
        {
            if (p % 2 == 0)
            {
                ++even_position;
            }
            else
            {
                ++odd_position;
            }
        }
        return min(even_position, odd_position);
    }
};
