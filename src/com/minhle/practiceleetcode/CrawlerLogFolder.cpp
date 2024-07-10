class Solution {
public:
    int minOperations(vector<string>& logs) {
        int step = 0;
        for (const auto &log : logs)
        {
            if (log[0] == '.' && log[1] == '.')
            {
                if (step == 0)
                {
                    continue;
                }
                --step;
            }
            else if (log[0] == '.' && log[1] == '/')
            {
                continue;
            }
            else
            {
                ++step;
            }
        }
        return step;
    }
};
