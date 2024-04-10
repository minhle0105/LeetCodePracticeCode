class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        priority_queue<int, vector<int>, greater<int>> heap;
        int n = static_cast<int>(deck.size());
        sort(deck.begin(), deck.end());
        queue<string> q;
        int i = 0;
        int count_X = 1;
        bool push_variable = false;
        vector<string> initial_orders;
        initial_orders.reserve(n);

        while (q.size() < n)
        {
            if (push_variable)
            {
                auto value = "X" + to_string(count_X);
                q.push(value);
                initial_orders.push_back(value);
                ++count_X;
            }
            else
            {
                auto value = to_string(deck[i]);
                q.push(value);
                initial_orders.push_back(value);
                ++i;
            }
            push_variable = !push_variable;
        }

        while (i < n)
        {
            heap.push(deck[i]);
            ++i;
        }
        
        unordered_map<string, int> variable_map;
        while (q.size() >= 2)
        {
            auto first = q.front();
            q.pop();
            auto second = q.front();
            q.pop();
            if (first[0] == 'X')
            {
                variable_map[first] = heap.top();
                heap.pop();
            }
            q.push(second);
        }
        if (!q.empty())
        {
            auto curr = q.front();
            q.pop();
            if (curr[0] == 'X')
            {
                variable_map[curr] = heap.top();
                heap.pop();
            }
        }

        vector<int> res;
        res.reserve(n);
        for (const auto &num : initial_orders)
        {
            if (num[0] == 'X')
            {
                res.push_back(variable_map[num]);
            }
            else
            {
                res.push_back(stoi(num));
            }
        }
        return res;
    }
};
