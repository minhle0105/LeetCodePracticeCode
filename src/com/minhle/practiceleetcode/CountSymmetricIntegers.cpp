class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int res = 0;
        for (int num = low; num <= high; ++num)
        {
            auto num_str = to_string(num);
            int n = num_str.size();
            if (n % 2 != 0)
            {
                continue;
            }
            int left_sum = 0;
            int right_sum = 0;
            for (int i = 0; i < n / 2; ++i)
            {
                left_sum += (num_str[i] + 'a');
                right_sum += (num_str[n - i - 1] + 'a');
            }
            if (left_sum == right_sum)
            {
                ++res;
            }
        }
        return res;
    }
};
