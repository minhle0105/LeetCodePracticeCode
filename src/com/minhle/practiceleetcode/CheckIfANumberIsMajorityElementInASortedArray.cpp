#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        unordered_map<int, int> counter;
        for (int num : nums)
        {
            ++counter[num];
        }
        return counter[target] > nums.size() / 2;
    }
};
