#include "AllNecessaryHeaders.h"

class Solution {
public:
    int get_distances(const vector<int> &distance, int start, int destination)
    {
        int clockwise_distance = 0;
        int counter_clockwise_distance = 0;
        for (int curr = start; curr < destination; ++curr)
        {
            clockwise_distance += distance[curr];
        }
        for (int curr = destination; curr < distance.size(); ++curr)
        {
            counter_clockwise_distance += distance[curr];
        }
        for (int curr = 0; curr < start; ++curr)
        {
            counter_clockwise_distance += distance[curr];
        }
        return min(clockwise_distance, counter_clockwise_distance);
    }

    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        return start < destination ? get_distances(distance, start, destination) : get_distances(distance, destination, start);
    }
};
