#include "AllNecessaryHeaders.h"

struct Car
{
public:
    double position;
    int speed;

    Car(double position, int speed) : position(position), speed(speed) {};

    bool operator<(const Car &car) const
    {
        return this->position < car.position;
    }
};

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed)
    {
        vector<Car> cars;
        for (int i = 0; i < position.size(); ++i)
        {
            cars.emplace_back(static_cast<double>(position[i]), speed[i]);
        }
        sort(cars.begin(), cars.end());
        stack<Car> st;
        st.push(cars.back());
        for (int i = cars.size() - 2; i >= 0; --i)
        {
            if (cars[i].speed > st.top().speed)
            {
                auto top_car = st.top();
                double time_top_car = time_to_reach_destination(top_car, target);
                double time_current_car = time_to_reach_destination(cars[i], target);
                if (time_current_car > time_top_car)
                {
                    st.push(cars[i]);
                }
            }
            else
            {
                st.push(cars[i]);
            }
        }
        return st.size();
    }
private:
    double time_to_reach_destination(const Car &car, int target)
    {
        return static_cast<double>(target - car.position) / car.speed;
    }
};
