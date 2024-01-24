#include <vector>

using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int curr = left; curr <= right; ++curr)
        {
            if (selfDividing(curr))
            {
                res.push_back(curr);
            }
        }
        return res;
    }

    bool selfDividing(int num)
    {
        int curr = num;
        while (curr != 0)
        {
            int digit = curr % 10;
            if (digit == 0 || num % digit != 0)
            {
                return false;
            }
            curr /= 10;
        }
        return true;
    }
};
