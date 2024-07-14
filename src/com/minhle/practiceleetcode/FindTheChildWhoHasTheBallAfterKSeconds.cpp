class Solution {
public:
    int numberOfChild(int n, int k) {
        int current_child = 0;
        int current_second = 0;
        bool going_positive = true;
        while (current_second < k)
        {
            if (current_child == 0 && !going_positive)
            {
                going_positive = true;
            }
            else if (current_child == n - 1 && going_positive)
            {
                going_positive = false;
            }
            current_child += going_positive ? 1 : -1;
            ++current_second;
        }
        return current_child;
    }
};
