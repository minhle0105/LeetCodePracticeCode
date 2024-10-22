class Solution {
public:
    struct Counter
    {
        int value;
        int frequency;

        Counter(int value, int frequency) : value(value), frequency(frequency){};

        bool operator<(const Counter &c) const
        {
            return this->frequency > c.frequency;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<Counter> heap;
        unordered_map<int, int> counter_;
        for (int num : nums)
        {
            ++counter_[num];
        }  
        for (const auto &pair : counter_)
        {
            heap.push(Counter{pair.first, pair.second});
            if (heap.size() > k)
            {
                heap.pop();
            }
        }
        vector<int> res;
        while (!heap.empty())
        {
            res.push_back(heap.top().value);
            heap.pop();
        }
        return res;
    }
};
