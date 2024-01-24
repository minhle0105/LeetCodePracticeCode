#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        int num = 1;
        int threshold = n % 2 == 0 ? n : n - 1;
        while (res.size() < threshold)
        {
            res.push_back(num);
            res.push_back(num * (-1));
            ++num;
        }
        if (threshold == n - 1)
        {
            res.push_back(0);
        }
        return res;
    }
};
