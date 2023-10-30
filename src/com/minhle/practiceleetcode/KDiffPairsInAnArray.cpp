#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        set<pair<int, int>> s;
        unordered_map<int, int> counter;
        for (int num : nums)
        {
            ++counter[num];
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            int target = nums.at(i) + k;
            if (counter.find(target) != counter.end())
            {
                if (nums.at(i) == target)
                {
                    if (counter[target] > 1)
                    {
                        s.insert({target, target});
                    }
                }
                else
                {
                    s.insert({min(nums.at(i), target), max(nums.at(i), target)});
                }
            }
        }
        return s.size();
    }
};