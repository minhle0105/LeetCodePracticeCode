class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        for (int i = 0; i < nums1.size() - 1; ++i)
        {
            for (int j = i + 1; j < nums1.size(); ++j)
            {
                if (equal_array(nums1, nums2, i, j))
                {
                    for (int k = 0; k < nums1.size(); ++k)
                    {
                        if (k != i && k != j)
                        {
                            return nums2[0] - nums1[k];
                        }
                    }
                }
            }
        }
        return -1;
    }

    bool equal_array(const vector<int> &nums1, const vector<int> &nums2, int skip1, int skip2)
    {
        int i = 0;
        int j = 0;
        unordered_set<int> diffs;
        while (i < nums1.size() && j < nums2.size())
        {
            if (i == skip1 || i == skip2)
            {
                ++i;
                continue;
            }
            diffs.insert(nums2[j] - nums1[i]);
            ++i;
            ++j;
        }
        return diffs.size() == 1;
    }
};
