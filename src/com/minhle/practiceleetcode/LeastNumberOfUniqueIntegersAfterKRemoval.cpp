class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> counter;
        for (int num : arr)
        {
            ++counter[num];
        }
        vector<pair<int, int>> counter_pairs(counter.begin(), counter.end());
        sort(counter_pairs.begin(), counter_pairs.end(), [](const pair<int, int> &p1, const pair<int, int> &p2){
            return p1.second < p2.second;
        });
        
        int frequency_sum = 0;
        int pivot = -1;
        for (auto &pair : counter_pairs)
        {
            ++pivot;
            frequency_sum += pair.second;
            if (frequency_sum == k)
            {
                return counter_pairs.size() - pivot - 1;
            }
            else if (frequency_sum > k)
            {
                return counter_pairs.size() - pivot;
            }
        }
        return -1;
    }
};
