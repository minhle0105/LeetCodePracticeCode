class Solution {
public:
    int passThePillow(int n, int time) {
        int current_second = 0;
        int current_index = 1;
        int direction = 1;
        while (current_second < time)
        {
            current_index += direction;
            if (current_index == 1)
            {
                direction = 1;
            }
            else if (current_index == n)
            {
                direction = -1;
            }
            ++current_second;
        }
        return current_index;
    }
};
