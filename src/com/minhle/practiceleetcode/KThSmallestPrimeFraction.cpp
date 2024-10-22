class Solution {
public:
    struct Pair
    {
        int x;
        int y;
        double fraction;

        Pair(int x, int y) : x(x), y(y) {
            this->fraction = static_cast<double>(x) / y;
        };

        bool operator<(const Pair &p) const
        {
            return this->fraction < p.fraction;
        }
    };

    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<Pair> heap;
        for (int i = 0; i < arr.size() - 1; ++i)  
        {
            for (int j = i + 1; j < arr.size(); ++j)
            {
                heap.push(Pair{arr[i], arr[j]});
                if (heap.size() > k)
                {
                    heap.pop();
                }
            }
        }
        return vector<int>{heap.top().x, heap.top().y};
    }
};
