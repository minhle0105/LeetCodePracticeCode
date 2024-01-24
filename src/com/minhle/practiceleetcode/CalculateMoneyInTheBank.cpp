#include "AllNecessaryHeaders.h"

class Solution {
public:
    int totalMoney(int n) {
        int current_week = 0;
        int total_week = n / 7;
        int res = 0;
        int monday_amount = 1;
        int nDaysCurrentWeek = 7;
        while (current_week != total_week)
        {
            res += ((monday_amount + monday_amount + nDaysCurrentWeek - 1) * nDaysCurrentWeek) / 2;
            ++current_week;
            ++monday_amount;
        }
        if (n % 7 != 0)
        {
            nDaysCurrentWeek = n % 7;
            res += ((monday_amount + monday_amount + nDaysCurrentWeek - 1) * nDaysCurrentWeek) / 2;
        }
        return res;
    }
};