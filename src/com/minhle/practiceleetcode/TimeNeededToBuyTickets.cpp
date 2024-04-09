class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < tickets.size(); ++i)
        {
            q.push({i, tickets[i]});
        }
        while (!q.empty())
        {
            auto top = q.front();
            q.pop();
            --top.second;
            ++time;
            if (top.first == k && top.second == 0)
            {
                return time;
            }
            if (top.second != 0)
            {
                q.push(top);
            }
        }
        return time;
    }
};
