class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> number_to_index;
        for (int i = 0; i < nums2.size(); ++i)
        {
            number_to_index[nums2[i]] = i;
        }
        vector<int> res;
        for (int num : nums1)
        {
            res.push_back(number_to_index[num]);
        }
        return res;
    }
};
