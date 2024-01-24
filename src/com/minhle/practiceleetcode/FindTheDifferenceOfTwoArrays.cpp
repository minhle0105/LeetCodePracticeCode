#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> set1;
        set<int> set2;
        for (int num : nums1)
        {
            set1.insert(num);
        }
        for (int num : nums2)
        {
            set2.insert(num);
        }
        vector<int> res1;
        vector<int> res2;
        for (int num : set1)
        {
            if (set2.find(num) == set2.end())
            {
                res1.push_back(num);
            }
        }
        for (int num : set2)
        {
            if (set1.find(num) == set1.end())
            {
                res2.push_back(num);
            }
        }
        vector<vector<int>> res;
        res.push_back(res1);
        res.push_back(res2);
        return res;
    }
};
