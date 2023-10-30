#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        set<int> set;
        for (const auto &point : nums)
        {
            for (int num = point.at(0); num <= point.at(1); ++num)
            {
                set.insert(num);
            }
        }
        return set.size();
    }
};
