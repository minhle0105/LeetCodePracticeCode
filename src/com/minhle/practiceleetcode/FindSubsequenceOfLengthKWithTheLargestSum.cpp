#include <queue>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> nums_with_index;
        for (int i = 0; i < nums.size(); ++i)
        {
            nums_with_index.push_back({nums[i], i});
        }        
        sort(nums_with_index.begin(), nums_with_index.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b){
            return a.first < b.first;
        });
        priority_queue<int, vector<int>, greater<int>> res_pos;
        int i = nums_with_index.size() - 1;
        while (res_pos.size() < k)
        {
            res_pos.push(nums_with_index[i].second);
            --i;
        }
        vector<int> res;
        while (!res_pos.empty())
        {
            res.push_back(nums[res_pos.top()]);
            res_pos.pop();
        }
        return res;
    }
};

