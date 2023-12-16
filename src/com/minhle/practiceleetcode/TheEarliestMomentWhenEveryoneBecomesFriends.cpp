#include "AllNecessaryHeaders.h"

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        parents.resize(n, -1);
        size.resize(n, 1);
        sort(logs.begin(), logs.end(), [](const vector<int> &log1, const vector<int> &log2){
            return log1.front() < log2.front();
        });

        int count = n;
        for (const auto &log : logs)
        {
            if (union_set(log[1], log[2]))
            {
                --count;
            }

            if (count == 1)
            {
                return log.front();
            }
        }
        return -1;
    }


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

private:
    vector<int> parents;
    vector<int> size;
};
