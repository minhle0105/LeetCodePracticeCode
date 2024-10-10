class Solution {
public:
    vector<long long> maximumCoins(vector<int>& heroes, vector<int>& monsters, vector<int>& coins) {
        vector<pair<int, int>> mc;
        mc.reserve(monsters.size());

        for (int i = 0; i < monsters.size(); ++i)
        {
            mc.push_back({monsters[i], coins[i]});
        }
        sort(mc.begin(), mc.end(), [](const pair<int, int> &p1, const pair<int, int> &p2){
            return p1.first < p2.first;
        });

        vector<long long> prefix_sums = {mc[0].second};
        for (int i = 1; i < monsters.size(); ++i)
        {
            prefix_sums.push_back(prefix_sums.back() + mc[i].second);
        }

        vector<long long> res;
        res.reserve(heroes.size());

        for (int i = 0; i < heroes.size(); ++i)
        {
            int strongest_enemy = binary_search(mc, heroes[i]);
            if (strongest_enemy == -1)
            {
                res.push_back(0);
            }
            else
            {
                res.push_back(prefix_sums[strongest_enemy]);
            }
        } 

        return res;
    }

    int binary_search(const vector<pair<int, int>> &mc, int hero)
    {
        int left = 0;
        int right = mc.size() - 1;

        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            if (mc[mid].first <= hero)
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }
        if (mc[right].first <= hero)
        {
            return right;
        }
        return mc[left].first <= hero ? left : -1;
    }
};
