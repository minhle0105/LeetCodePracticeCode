class FindSumPairs {
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2_) {
        for (int num : nums1)
        {
            ++counter1[num];
        }
        for (int num : nums2_)
        {
            nums2.push_back(num);
            ++counter2[num];
        }
    }
    
    void add(int index, int val) {
        int current_num = nums2[index];
        --counter2[current_num];
        if (counter2[current_num] == 0)
        {
            counter2.erase(current_num);
        }
        current_num += val;
        nums2[index] = current_num;
        ++counter2[current_num];
    }
    
    int count(int tot) {
        int res = 0;
        for (const auto &pair : counter1)
        {
            int diff = tot - pair.first;
            if (counter2.find(diff) != counter2.end())
            {
                res += (pair.second) * (counter2[diff]);
            }
        }
        return res;
    }
private:
    vector<int> nums2;
    unordered_map<int, int> counter1;
    unordered_map<int, int> counter2;
};







 */
