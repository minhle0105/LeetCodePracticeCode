#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long res = 0;
        int first = 0;
        int second = 0;
        multiset<int> min_max;
        while (first < nums.size())
        {
            min_max.insert(nums.at(first));
            ++first;
            while (!eval(min_max))
            {
                min_max.erase(min_max.find(nums.at(second)));
                ++second;
            }
            res += (first - second);
        }
        return res;
    }

    bool eval(const multiset<int> &min_max)
    {
        auto begin = *min_max.begin();
        auto end = *(--min_max.end());
        auto eval = abs(begin - end);
        auto check_left_bound = 0 <= eval;
        auto check_right_bound = eval <= 2;
        auto res = check_left_bound && check_right_bound;
        return res;
    }
};