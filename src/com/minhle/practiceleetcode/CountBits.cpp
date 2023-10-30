#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for (int i = 0; i <= n; ++i)
        {
            res.push_back(binary_convert(i));
        }
        return res;
    }

    int binary_convert(int num)
    {
        int curr = num;
        int res = 0;
        while (curr != 0)
        {
            res += curr % 2 == 1 ? 1 : 0;
            curr /= 2;
        }
        res += curr % 2 == 1 ? 1 : 0;
        curr /= 2;
        return res;
    }
};
