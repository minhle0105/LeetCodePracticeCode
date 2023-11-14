#include "AllNecessaryHeaders.h"

class StockSpanner {
public:
    StockSpanner() {

    }

    int next(int price) {
        int next_last_ind = prices.size();
        prices.push_back(price);
        while (!mono_dec_st.empty() && prices.back() >= mono_dec_st.top().second)
        {
            mono_dec_st.pop();
        }
        if (mono_dec_st.empty())
        {
            mono_dec_st.push({next_last_ind, price});
            return next_last_ind + 1;
        }
        int leftmost_ind = mono_dec_st.top().first;
        mono_dec_st.push({next_last_ind, price});
        return next_last_ind - leftmost_ind;
    }
private:
    vector<int> prices;
    stack<pair<int, int>> mono_dec_st;
};
