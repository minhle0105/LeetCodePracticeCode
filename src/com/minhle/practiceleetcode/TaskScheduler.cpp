class Solution {
public:
    struct Comparator
    {
        bool operator()(const pair<char, int> &p1, const pair<char, int> &p2)
        {
            return p1.second < p2.second;
        }
    };
    int leastInterval(vector<char>& tasks, int n)
    {
        unordered_map<char, int> counter;
        for (char task : tasks)
        {
            ++counter[task];
        }
        priority_queue<pair<char, int>, vector<pair<char, int>>, Comparator> heap;
        queue<pair<pair<char, int>, int>> q;

        for (const auto &pair : counter)
        {
            heap.push(pair);
        }
        int current_time = 0;
        while (!heap.empty() || !q.empty())
        {
            ++current_time;
            if (!heap.empty())
            {
                auto next_process = heap.top();
                heap.pop();
                --next_process.second;
                if (next_process.second > 0)
                {
                    q.emplace(next_process, current_time + n);
                }
            }
            if (current_time == q.front().second)
            {
                auto temp = q.front();
                q.pop();
                heap.push(temp.first);
            }
        }
        return current_time;
    }
};
