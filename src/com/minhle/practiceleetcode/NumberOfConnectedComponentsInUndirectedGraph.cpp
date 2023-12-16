#include "AllNecessaryHeaders.h"

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        parents.resize(n, -1);
        size.resize(n, 1);
        int res = n;
        for (const auto &edge : edges)
        {
            if (union_set(edge.front(), edge.back()))
            {
                --res;
            }
        }
        return res;
    }
private:
    vector<int> parents;
    vector<int> size;

    int find(int val)
    {
        if (parents[val] == -1)
        {
            return val;
        }
        parents[val] = find(parents[val]);
        return parents[val];
    }

    bool union_set(int a, int b)
    {
        int lead_a = find(a);
        int lead_b = find(b);
        if (lead_a == lead_b)
        {
            return false;
        }
        if (size[lead_a] > size[lead_b])
        {
            parents[lead_b] = lead_a;
            size[lead_a] += size[lead_b];
        }
        else
        {
            parents[lead_a] = lead_b;
            size[lead_b] += size[lead_a];
        }
        return true;
    }
};
