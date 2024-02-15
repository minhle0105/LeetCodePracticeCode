class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> groups;
        int left = 0;
        int right = 0;
        while (left < s.size())
        {
            while (right < s.size() && s[left] == s[right])
            {
                ++right;
            }
            if (right - left >= 3)
            {
                groups.push_back({left, right - 1});
            }
            left = right;
        }
        return groups;
    }
};
