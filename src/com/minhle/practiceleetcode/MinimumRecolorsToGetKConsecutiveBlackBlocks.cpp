#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int res = INT_MAX;
        vector<int> count_W;
        count_W.push_back(0);
        for (char c : blocks)
        {
            count_W.push_back( (c == 'W' ? count_W.back() + 1 : count_W.back()));
        }
        int first = k - 1;
        int second = 0;
        while (first < blocks.size())
        {
            res = min(count_W.at(first + 1) - count_W.at(second), res);
            ++first;
            ++second;
        }
        return res;
    }
};
