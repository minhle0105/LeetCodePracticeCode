#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> res;
        res.reserve(people.size());
        map<int, int> diff;
        for (const auto &flower : flowers)
        {
            ++diff[flower.at(0)];
            --diff[flower.at(1) + 1];
        }
        vector<int> pos;
        vector<int> prefix;
        int curr = 0;
        for (const auto &pair : diff)
        {
            pos.push_back(pair.first);
            curr += pair.second;
            prefix.push_back(curr);
        }
        for (int person : people)
        {
            res.push_back(binary_search(pos, prefix, person));
        }
        return res;
    }

    int binary_search(const vector<int> &pos, const vector<int> &prefix, int target)
    {
        int left = 0;
        int right = pos.size() - 1;
        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            if (pos.at(mid) == target)
            {
                return prefix.at(mid);
            }
            if (pos.at(mid) < target)
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }
        if (pos.at(right) <= target)
        {
            return prefix.at(right);
        }
        if (pos.at(left) <= target)
        {
            return prefix.at(left);
        }
        return 0;
    }
};