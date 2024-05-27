class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for (const auto &operation : operations)
        {
            if (operation.front() == '+' || operation.back() == '+')
            {
                ++x;
            }
            else
            {
                --x;
            }
        }
        return x;
    }
};
