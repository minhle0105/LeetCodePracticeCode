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
    vector<double> getCollisionTimes(vector<vector<int>>& cars_data) {
        vector<Car> cars;
        cars.reserve(cars_data.size());
        for (const auto &car : cars_data)
        {
            cars.emplace_back(static_cast<double>(car.front()), car.back());
        }
        sort(cars.begin(), cars.end());
        vector<double> res(cars.size(), -1.0);
        stack<Car> st;
        for (int i = cars.size() - 1; i >= 0; --i)
        {
            while (!st.empty() && cars[i].speed <= st.top().speed)
            {
                st.pop();
            }
            if (st.size() == 1)
            {
                res[i] = collision_time(cars[i], collision_position(cars[i], st.top()));
            }
            // consider current_car = A, two next car to the right is B, C
            while (st.size() >= 2)
            {
                auto closer_car = st.top();
                st.pop();
                auto further_car = st.top();
                st.pop();
                double collision_position_between_closer_and_further_cars = collision_position(closer_car, further_car);
                double collision_position_between_current_car_and_further_car = collision_position(cars[i], further_car);
                if (collision_position_between_closer_and_further_cars < collision_position_between_current_car_and_further_car)
                {
                    // this case is when B and C collides first and then forms a fleet BC with speed of C, because C has
                    // lower speed than B.
                    st.push(further_car);
                }
                else
                {
                    // this casae is when A and B collides before B and C collides
                    st.push(further_car);
                    st.push(closer_car);
                    res[i] = collision_time(cars[i], collision_position(cars[i], closer_car));
                    break;
                }
            }
            if (!st.empty())
            {
                res[i] = collision_time(cars[i], collision_position(cars[i], st.top()));
            }
            st.push(cars[i]);
        }
        return res;
    }
private:
    double collision_position(const Car &car1, const Car &car2)
    {
        return static_cast<double>((car2.speed * car1.position - car1.speed * car2.position)) / (car2.speed - car1.speed);
    }

    double collision_time(const Car &car, double collision_position)
    {
        return (collision_position - car.position) / car.speed;
    }
};
