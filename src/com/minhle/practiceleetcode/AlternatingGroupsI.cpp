class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int res = 0;
        int n = static_cast<int>(colors.size());
        for (int i = 1; i < n - 1; ++i)
        {
            if (colors[i] != colors[i - 1] && colors[i] != colors[i + 1])
            {
                ++res;
            }
        }
        if (colors.back() != colors[n - 2] && colors.back() != colors.front())
        {
            ++res;
        }
        if (colors.front() != colors.back() && colors.front() != colors[1])
        {
            ++res;
        }
        return res;
    }
};
