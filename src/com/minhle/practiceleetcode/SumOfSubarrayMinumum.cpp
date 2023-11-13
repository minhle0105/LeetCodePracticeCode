#include "AllNecessaryHeaders.h"

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const long MODULO = pow(10, 9) + 7;
        vector<pair<int, int>> bounds(arr.size(), pair<int, int>{-1, -1});
        stack<pair<int, int>> mono_increasing_stack;

        // span to the right
        for (int i = 0; i < arr.size(); ++i)
        {
            while (!mono_increasing_stack.empty() && arr[i] <= mono_increasing_stack.top().second)
            {
                bounds[mono_increasing_stack.top().first].second = i;
                mono_increasing_stack.pop();
            }
            mono_increasing_stack.push({i, arr[i]});
        }
        while (!mono_increasing_stack.empty())
        {
            bounds[mono_increasing_stack.top().first].second = arr.size();
            mono_increasing_stack.pop();
        }

        // span to the left
        for (int i = arr.size() - 1; i >= 0; --i)
        {
            while (!mono_increasing_stack.empty() && arr[i] < mono_increasing_stack.top().second)
            {
                bounds[mono_increasing_stack.top().first].first = i;
                mono_increasing_stack.pop();
            }
            mono_increasing_stack.push({i, arr[i]});
        }

        while (!mono_increasing_stack.empty())
        {
            bounds[mono_increasing_stack.top().first].first = -1;
            mono_increasing_stack.pop();
        }

        int res = 0;
        for (int i = 0; i < bounds.size(); ++i)
        {
            auto current_num = arr[i];
            auto left = bounds[i].first;
            auto right = bounds[i].second;
            auto n_elements_on_the_left = i - left - 1;
            auto n_elements_on_the_right = right - i - 1;
            auto number_of_subarray_with_current_num_as_min = ((n_elements_on_the_right + 1) * (n_elements_on_the_left + 1)) % MODULO;
            res += (current_num * number_of_subarray_with_current_num_as_min) % MODULO;
            res %= MODULO;
        }
        return res;
    }
};