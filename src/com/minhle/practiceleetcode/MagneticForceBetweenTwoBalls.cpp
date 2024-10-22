class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int left = 0;
        int right = position.back();

        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            if (place_balls(position, m, mid))
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }
        return place_balls(position, m, right) ? right : left;
    }

    bool place_balls(const vector<int> &positions, int m, int dist)
    {
        int count = 1;
        int last_position = positions[0];

        for (int i = 1; i < positions.size(); ++i)
        {
            if (positions[i] - last_position >= dist)
            {
                ++count;
                last_position = positions[i];
            }
            if (count == m)
            {
                return true;
            }
        }
        return false;
    }
};
