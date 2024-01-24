#include "AllNecessaryHeaders.h"

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        priority_queue<int> max_heap;

        for (int pile : piles)
        {
            max_heap.push(pile);
        }

        int res = 0;
        int nPileTaken = 0;

        while (nPileTaken < piles.size())
        {
            max_heap.pop();
            
            res += max_heap.top();
            max_heap.pop();

            nPileTaken += 3;
        }
        return res;
    }
};
