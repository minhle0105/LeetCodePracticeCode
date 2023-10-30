#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        set<int> covered;
        for (const auto &range : ranges)
        {
            int low = range.at(0);
            int high = range.at(1);
            for (int num = low; num <= high; ++num)
            {
                covered.insert(num);
            }
        }
        for (int num = left; num <= right; ++num)
        {
            if (covered.find(num) == covered.end())
            {
                return false;
            }
        }
        return true;
    }
};
