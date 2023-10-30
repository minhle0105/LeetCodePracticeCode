#include <vector>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        const int nLimit = 1690;
        vector<int> uglyNums(nLimit, 0);
        uglyNums[0] = 1;
        int two = 0;
        int three = 0;
        int five = 0;
        int i = 1;
        while (i < nLimit)
        {
            int a = 2 * uglyNums.at(two);
            int b = 3 * uglyNums.at(three);
            int c = 5 * uglyNums.at(five);

            int ugly = min(min(a, b), c);
            if (ugly == a)
            {
                ++two;
            }
            if (ugly == b)
            {
                ++three;
            }
            if (ugly == c)
            {
                ++five;
            }
            uglyNums.at(i) = ugly;
            ++i;
        }
        return uglyNums.at(n - 1);
    }
};
