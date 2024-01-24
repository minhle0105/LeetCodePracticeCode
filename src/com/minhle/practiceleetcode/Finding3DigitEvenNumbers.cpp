#include "AllNecessaryHeaders.h"

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int, int> counter;
        for (int digit : digits)
        {
            ++counter[digit];
        }
        set<int> all_numbers;
        for (int number = 100; number < 1000; number += 2)
        {
            unordered_map<int, int> number_counter = count_digit(number);
            bool can_form = true;
            for (const auto &pair : number_counter)
            {
                if (counter.find(pair.first) == counter.end() || counter[pair.first] < pair.second)
                {
                    can_form = false;
                    break;
                }
            }
            if (can_form)
            {
                all_numbers.insert(number);
            }
        }
        vector<int> res;
        res.reserve(all_numbers.size());
        for (int number : all_numbers)
        {
            res.push_back(number);
        }
        return res;
    }
private:
    unordered_map<int, int> count_digit(int number)
    {
        unordered_map<int, int> counter;
        while (number != 0)
        {
            ++counter[number % 10];
            number /= 10;
        }
        return counter;
    }
};
