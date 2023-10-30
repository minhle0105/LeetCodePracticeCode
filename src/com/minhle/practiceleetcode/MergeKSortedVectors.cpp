#include <vector>

using namespace std;

class MergeKSortedVectors
{
public:
    vector<int> mergeKSortedList(vector<vector<int>> &sortedLists)
    {
        if (sortedLists.empty() == 0)
        {
            return vector<int>{};
        }
        if (sortedLists.size() == 1)
        {
            return sortedLists.front();
        }
        vector<int> res = mergeTwoSortedList(sortedLists.at(0), sortedLists.at(1));
        for (int i = 2; i < sortedLists.size(); ++i)
        {
            res = mergeTwoSortedList(res, sortedLists.at(i));
        }
        return res;
    }
    vector<int> mergeTwoSortedList(const vector<int> &nums1, const vector<int> &nums2)
    {
        vector<int> res;
        res.reserve(nums1.size() + nums2.size());
        int i = 0;
        int j = 0;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1.at(i) < nums2.at(j))
            {
                res.push_back(nums1.at(i));
                ++i;
            }
            else
            {
                res.push_back(nums2.at(j));
                ++j;
            }
        }
        while (i < nums1.size())
        {
            res.push_back(nums1.at(i));
            ++i;
        }
        while (j < nums2.size())
        {
            res.push_back(nums2.at(j));
            ++j;
        }
        return res;
    }
};
