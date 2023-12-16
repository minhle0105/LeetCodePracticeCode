#include "AllNecessaryHeaders.h"

class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> current_set;
        for (int card : cards)
        {
            current_set.push_back(static_cast<double>(card));
        }
        return backtracking(current_set);
    }
private:
    const double EPSILON = 1e-6;

    bool backtracking(vector<double> current_set)
    {
        if (current_set.size() == 1)
        {
            return abs(current_set.front() - 24) < EPSILON;
        }
        for (int i = 0; i < current_set.size() - 1; ++i)
        {
            for (int j = i + 1; j < current_set.size(); ++j)
            {
                vector<double> new_set;
                for (int k = 0; k < current_set.size(); ++k)
                {
                    if (k != i && k != j)
                    {
                        new_set.push_back(current_set[k]);
                    }
                }
                auto values = generate_values(current_set[i], current_set[j]);
                for (double value : values)
                {
                    new_set.push_back(value);
                    if (backtracking(new_set))
                    {
                        return true;
                    }
                    new_set.pop_back();
                }
            }
        }
        return false;
    }

    vector<double> generate_values(double a, double b)
    {
        vector<double> res;
        res.push_back(a + b);
        res.push_back(a - b);
        res.push_back(b - a);
        res.push_back(a * b);
        if (b != 0)
        {
            res.push_back(a / b);
        }
        if (a != 0)
        {
            res.push_back(b / a);
        }
        return res;
    }
};
