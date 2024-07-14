class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int> res;
        int current_player = 1;
        int i = 1;
        unordered_set<int> received;
        while (received.find(current_player) == received.end())
        {
            received.insert(current_player);
            int step = i * k;
            int step_count = 0;
            while (step_count < step)
            {
                if (current_player == n)
                {
                    current_player = 1;
                }
                else
                {
                    ++current_player;
                }
                ++step_count;
            }
            ++i;
        }
        for (int i = 1; i <= n; ++i)
        {
            if (received.find(i) == received.end())
            {
                res.push_back(i);
            }
        }
        return res;
    }
};
