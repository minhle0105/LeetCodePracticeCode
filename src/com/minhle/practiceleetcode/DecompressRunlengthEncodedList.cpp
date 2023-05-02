#include <cstdint>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> res;
        for (size_t i = 0; i < nums.size() - 1; i += 2)
        {
            for (int j = 0; j < nums.at(i); ++j)
            {
                res.push_back(nums.at(i + 1));
            }
        }
        return res;
    }
};
