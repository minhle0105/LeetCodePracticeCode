#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<int> prefix_sum_modulo_k;
        prefix_sum_modulo_k.push_back(nums.at(0) % k);
        for (int i = 1; i < nums.size(); ++i)
        {
            prefix_sum_modulo_k.push_back((prefix_sum_modulo_k.back() + nums.at(i)) % k);
            if (prefix_sum_modulo_k.back() % k == 0 && i >= 1)
            {
                return true;
            }
        }
        map<int, int> map_position;
        for (int i = 0; i < prefix_sum_modulo_k.size(); ++i)
        {
            if (map_position.find(prefix_sum_modulo_k.at(i)) == map_position.end())
            {
                map_position[prefix_sum_modulo_k.at(i)] = i;
            }
            else
            {
                if (i - map_position[prefix_sum_modulo_k.at(i)] >= 2)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
