#include "AllNecessaryHeaders.h"

struct Food
{
public:
    string name;
    int rating;

    Food(string name, int rating) : name(name), rating(rating) {};

    bool operator<(const Food &food) const
    {
        if (this->rating == food.rating)
        {
            return this->name > food.name;
        }
        return this->rating < food.rating;
    }
};

class FoodRatings {
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); ++i)
        {
            food_cuisine[foods[i]] = {cuisines[i], ratings[i]};
            cuisine_food[cuisines[i]].push(Food{foods[i], ratings[i]});
        }
    }

    void changeRating(string food, int newRating) {
        food_cuisine[food].second = newRating;
        cuisine_food[food_cuisine[food].first].push(Food{food, newRating});
    }

    string highestRated(string cuisine) {
        while (!cuisine_food.empty() &&
               cuisine_food[cuisine].top().rating != food_cuisine[cuisine_food[cuisine].top().name].second)
        {
            cuisine_food[cuisine].pop();
        }
        return cuisine_food[cuisine].top().name;
    }

private:
    unordered_map<string, pair<string, int>> food_cuisine;
    unordered_map<string, priority_queue<Food>> cuisine_food;
};
