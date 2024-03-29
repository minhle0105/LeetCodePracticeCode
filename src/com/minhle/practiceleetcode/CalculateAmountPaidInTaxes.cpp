class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double res = ((double(brackets[0][1])) / 100) * min(income, brackets[0][0]);
        income -= brackets[0][0];
        for (int i = 1; i < brackets.size(); ++i)
        {
            if (income <= 0)
            {
                break;
            }
            int income_here = min(income, brackets[i][0] - brackets[i - 1][0]);
            res += (double(brackets[i][1]) / 100) * income_here;
            income -= income_here;
        }
        return res;
    }
};
