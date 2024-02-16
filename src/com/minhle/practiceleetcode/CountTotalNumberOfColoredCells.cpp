#include "AllNecessaryHeaders.h"

class Solution
{
public:
    long long coloredCells(int n)
    {
        if (n == 1)
        {
            return 1;
        }
        long long nRows = (n * 2) - 1;

        long long middleRowIndex = nRows / 2;
        long long nCellsInMiddleRow = 1 + 2 * middleRowIndex;
        long long nRowsFirstHalf = ((nCellsInMiddleRow - 1) / 2) + 1;
        long long first_half_sum = ((1 + nCellsInMiddleRow) * nRowsFirstHalf) / 2;
        return (first_half_sum * 2) - nCellsInMiddleRow;
    }
};