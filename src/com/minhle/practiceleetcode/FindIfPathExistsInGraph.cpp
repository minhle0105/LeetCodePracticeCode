#include "AllNecessaryHeaders.h"

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        parents.resize(n, -1);
        size.resize(n, 1);
        for (const auto &edge : edges)
        {
            join(edge.front(), edge.back());
        }
        return find(source) == find(destination);
    }
private:
    vector<int> parents;
    vector<int> size;

    int find(int num)
    {
        return parents[num] == -1 ? num : find(parents[num]);
    }

    bool join(int a, int b)
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
