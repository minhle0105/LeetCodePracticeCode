#include "AllNecessaryHeaders.h"

class Solution {
public:
    vector<int> prefix_sum;
    int shipWithinDays(vector<int>& weights, int days) {
        prefix_sum.push_back(0);
        int max_weight = weights.front();
        int sum_weight = 0;
        for (int weight : weights)
        {
            prefix_sum.push_back(weight + prefix_sum.back());
            max_weight = max(max_weight, weight);
            sum_weight += weight;
        }

        int left = max_weight;
        int right = sum_weight;
        int n = weights.size();
        return binary_search(left, right, n, days);
    }
private:
    bool check_can_ship(int n, int days, int max_capacity)
    {
        int count_day = 0;
        int i = 0;
        while (i < n)
        {
            ++count_day;
            if (count_day > days)
            {
                return false;
            }
            i = binary_search(i, prefix_sum[i] + max_capacity);
        }
        return true;
    }

    int binary_search(int left, int right, int n, int days)
    {
        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            bool can_ship = check_can_ship(n, days, mid);
            if (can_ship)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return check_can_ship(n, days, left) ? left : right;
    }
    int binary_search(int left, int target)
    {
        int right = prefix_sum.size() - 1;

        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            if (prefix_sum[mid] <= target)
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }
        return prefix_sum[right] <= target ? right : left;
    }
};
