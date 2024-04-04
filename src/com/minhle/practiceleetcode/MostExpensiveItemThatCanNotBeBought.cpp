class Solution {
public:
    int mostExpensiveItem(int a, int b) {
        int threshold = a * b;

        vector<bool> can_buy(threshold + 1, false);
        can_buy[0] = true;
        
        int res = 0;

        for (int price = 1; price <= threshold; ++price)
        {
            if ((price >= a && can_buy[price - a]) || 
                (price >= b && can_buy[price - b]))
                {
                    can_buy[price] = true;
                }
            else
            {
                res = max(res, price);
            }
        }
        return res;
    }
};
