#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> distinctNumbers(vector<int>& nums, int k) {
        unordered_map<int, int> counter;
        vector<int> res;
        res.reserve(nums.size() - k + 1);
        for (int i = 0; i + k <= nums.size(); ++i)
        {
            int end_window = i + k - 1;
            if (i == 0)
            {
                for (int j = i; j <= end_window; ++j)
                {
                    if (counter.find(nums.at(j)) == counter.end())
                    {
                        counter[nums.at(j)] = 0;
                    }
                    ++counter[nums.at(j)];
                }
                res.push_back(counter.size());
            }
            else
            {
                if (counter.find(nums.at(end_window)) == counter.end())
                {
                    counter[nums.at(end_window)] = 0;
                }
                ++counter[nums.at(end_window)];
                --counter[nums.at(i - 1)];
                if (counter[nums.at(i - 1)] == 0)
                {
                    counter.erase(nums.at(i - 1));
                }
                res.push_back(counter.size());
            }
        }
        return res;
    }
};
