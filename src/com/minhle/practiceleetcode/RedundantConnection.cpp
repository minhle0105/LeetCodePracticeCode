class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> res;
        int n = edges.size();
        for (int i = 1; i <= n; ++i)
        {
            parents[i] = i;
            sizes[i] = 1;
        }
        for (const auto &edge : edges)
        {
            int a = edge.front();
            int b = edge.back();
            if (!join(a, b))
            {
                res = edge;
            }
        }
        return res;
    }
private:
    unordered_map<int, int> parents;
    unordered_map<int, int> sizes;

    int find_parent(int num)
    {
        if (parents[num] == num)
        {
            return num;
        }
        parents[num] = find_parent(parents[num]);
        return parents[num];
    }

    bool join(int a, int b)
    {
        int parent_a = find_parent(a);
        int parent_b = find_parent(b);
        if (parent_a == parent_b)
        {
            return false;
        }
        if (sizes[parent_a] > sizes[parent_b])
        {
            parents[parent_b] = parent_a;
            sizes[parent_a] += sizes[parent_b];
        }
        else
        {
            parents[parent_a] = parent_b;
            sizes[parent_b] += sizes[parent_a];
        }
        return true;
    }
};
