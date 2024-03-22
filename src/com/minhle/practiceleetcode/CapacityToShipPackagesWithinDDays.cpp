class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int max_weight = weights.front();
        int sum_weight = 0;
        for (int weight : weights)
        {
            max_weight = max(max_weight, weight);
            sum_weight += weight;
        }

        int left = max_weight;
        int right = sum_weight;

        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            bool can_ship = check_can_ship(weights, days, mid);
            if (can_ship)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return check_can_ship(weights, days, left) ? left : right;
    }

    bool check_can_ship(const vector<int> &weights, int days, int max_capacity)
    {
        int count_day = 0;
        int i = 0;
        while (i < weights.size())
        {
            int current_sum = 0;
            int j = i;
            while (j < weights.size() && current_sum < max_capacity)
            {
                current_sum += weights[j];
                if (current_sum <= max_capacity)
                {
                    ++j;
                }
                if (current_sum >= max_capacity)
                {
                    break;
                }
            }
            ++count_day;
            if (count_day > days)
            {
                return false;
            }
            i = j;
            current_sum = 0;
        }
        return true;
    }
    
};
