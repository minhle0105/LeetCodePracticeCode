#include "AllNecessaryHeaders.h"

class StockSpanner {
public:
    StockSpanner() {
        current_index = 0;
    }

    int next(int price) {
        while (!mono_dec_st.empty() && price >= mono_dec_st.top().second)
        {
            mono_dec_st.pop();
        }
        if (mono_dec_st.empty())
        {
            mono_dec_st.push({current_index, price});
            ++current_index;
            return current_index;
        }
        int leftmost_ind = mono_dec_st.top().first;
        mono_dec_st.push({current_index, price});
        int res = current_index - leftmost_ind;
        ++current_index;
        return res;
    }
private:
    stack<pair<int, int>> mono_dec_st;
    int current_index;
};
