#include <vector>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int right = 0;
        for (int pile : piles)
        {
            right = max(right, pile);
        }
        int left = 1;
        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            bool finish = can_finish(piles, mid, h);
            if (!finish)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return can_finish(piles, left, h) ? left : right;
    }

private:
    bool can_finish(const vector<int> &piles, int k, int h)
    {
        int hour = 0;
        for (int pile : piles)
        {
            if (pile <= k)
            {
                ++hour;
            }
            else
            {
                hour += (pile % k == 0) ? (pile / k) : (pile / k) + 1;
            }
            if (hour > h)
            {
                return false;
            }
        }
        return true;
    }
};