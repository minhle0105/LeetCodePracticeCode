#include "AllNecessaryHeaders.h"

class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        auto year1_data = extract_data_from_date(date1);
        auto year2_data = extract_data_from_date(date2);
        auto number_of_dates_1 = number_of_dates_from_1970_till_one_year_ahead(year1_data);
        auto number_of_dates_2 = number_of_dates_from_1970_till_one_year_ahead(year2_data);
        return abs(number_of_dates_2 - number_of_dates_1);
    }

private:
    vector<int> extract_data_from_date(const string &date)
    {
        vector<int> res;
        string data;
        for (int i = 0; i < date.size(); ++i)
        {
            if (date[i] == '-')
            {
                res.push_back(stoi(data));
                data = "";
            }
            else
            {
                data += date[i];
            }
        }
        res.push_back(stoi(data));
        return res;
    }

    int number_of_dates_from_1970_till_one_year_ahead(const vector<int> &date)
    {
        int year = date.front();
        int month = date[1];
        int day = date.back();
        int number_of_dates = 0;
        int curr_year = 1970;
        while (curr_year != year)
        {
            if (isLeapYear(curr_year))
            {
                number_of_dates += 366;
            }
            else
            {
                number_of_dates += 365;
            }
            ++curr_year;
        }
        int curr_month = 1;
        while (curr_month < month)
        {
            if (curr_month == 2)
            {
                if (isLeapYear(year))
                {
                    number_of_dates += 29;
                }
                else
                {
                    number_of_dates += 28;
                }
            }
            else if (month_with_31_days(curr_month))
            {
                number_of_dates += 31;
            }
            else
            {
                number_of_dates += 30;
            }
            ++curr_month;
        }
        number_of_dates += day;
        return number_of_dates;
    }

    bool month_with_31_days(int month)
    {
        return month == 1 ||
               month == 3 ||
               month == 5 ||
               month == 7 ||
               month == 8 ||
               month == 10 ||
               month == 12;
    }

    bool isLeapYear(int year)
    {
        return (year % 4 == 0 &&
               (year % 100 != 0 || year % 400 == 0));
    }
};
