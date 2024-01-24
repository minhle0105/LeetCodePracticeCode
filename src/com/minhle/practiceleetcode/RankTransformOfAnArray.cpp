#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> res(arr.size(), -1);
        unordered_map<int, vector<int>> element_pos;

        for (int i = 0; i < arr.size(); ++i)
        {
            element_pos[arr[i]].push_back(i);
        }

        sort(arr.begin(), arr.end());
        map<int, vector<int>> rankings;
        int rank = 1;
        int left = 0;
        int right = 0;
        while (right < arr.size())
        {
            while (right < arr.size() && arr[right] == arr[left])
            {
                rankings[rank].push_back(arr[right]);
                ++right;
            }
            left = right;
            ++rank;
        }
        for (const auto &ranking : rankings)
        {
            auto element = ranking.second.front();
            for (int pos : element_pos[element])
            {
                res[pos] = ranking.first;
            }
        }
        return res;
    }
};
