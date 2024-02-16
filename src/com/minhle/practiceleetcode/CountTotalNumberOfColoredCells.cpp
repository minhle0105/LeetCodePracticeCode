#include "AllNecessaryHeaders.h"

class Solution {
public:
    long long coloredCells(int n) {
        if (n == 1)
        {
            return 1;
        }
        int nRows = (n * 2) - 1;
        int left = 1;
        int right = 1;
        int count = 0;
        long long res = 0;
        while (count < nRows - 1)
        {
            res += (left + right);
            left += 2;
            right += 2;
            count += 2;
        }
        res += left;
        return res;
    }
};
