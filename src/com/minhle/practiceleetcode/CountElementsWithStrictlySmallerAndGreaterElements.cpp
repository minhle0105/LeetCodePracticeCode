#include <vector>

using namespace std;

class Solution {
public:
    int countElements(vector<int>& nums) {
        int min = INT_MAX;
        int max = INT_MIN;
        for (int num : nums)
        {
            min = min_(num, min);
            max = max_(num, max);
        }
        int res = 0;
        for (int num : nums)
        {
            if (num != min && num != max)
            {
                ++res;
            }
        }
        return res;
    }

    int min_(int a, int b)
    {
        return a > b ? b : a;
    }

    int max_(int a, int b)
    {
        return a > b ? a : b;
    }
};
