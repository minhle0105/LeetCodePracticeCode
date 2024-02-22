class Solution {
public:
    int distMoney(int money, int children) {
        if (money < children)
        {
            return -1;
        }
        vector<int> amounts(children, 1);
        money -= children;
        for (int i = 0; i < children; ++i)
        {
            if (money < 7)
            {
                amounts[i] += money;
                money = 0;
                if (amounts[i] == 4)
                {
                    int next = i == amounts.size() - 1 ? i - 1 : i + 1;
                    --amounts[i];
                    ++amounts[next];
                }
                break;
            }
            amounts[i] += 7;
            money -= 7;
        }
        if (money > 0)
        {
            for (int i = amounts.size() - 1; i >= 0; --i)
            {
                if (amounts[i] != 3)
                {
                    amounts[i] += money;
                    money = 0;
                    break;
                }
            }
        }
        int res = 0;
        for (int amount : amounts)
        {
            res += amount == 8 ? 1 : 0;
        }
        return res;
    }
};
