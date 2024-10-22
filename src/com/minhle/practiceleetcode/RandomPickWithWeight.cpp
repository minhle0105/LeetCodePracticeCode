class Solution {
public:
    Solution(vector<int>& weights) {
        prefix_sum.push_back(0);
        for (int weight : weights)
        {
            prefix_sum.push_back(weight + prefix_sum.back());
        }
        lower_bound = 0;
        upper_bound = prefix_sum.back();
    }
    
    int pickIndex() {
        int random_index = lower_bound + (rand() % (upper_bound - lower_bound));
        return binary_search(random_index);
    }
private:
    vector<int> prefix_sum;
    int lower_bound;
    int upper_bound;
    const long max_rand = 1000000L;
    int binary_search(int random_index)
    {
        int left = 0;
        int right = prefix_sum.size() - 1;

        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            if (prefix_sum[mid] > random_index)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        if (prefix_sum[left] > random_index)
        {
            return left - 1;
        }
        if (prefix_sum[right] > random_index)
        {
            return right - 1;
        }
        return -1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
