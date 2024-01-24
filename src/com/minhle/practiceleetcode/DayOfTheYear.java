package com.minhle.practiceleetcode;
import java.util.*;

public class DayOfTheYear {
    public int dayOfYear(String date) {
        String[] information = date.split("-");
        String year = information[0];
        boolean leapYear = isLeapYear(Integer.parseInt(year));
        Map<Integer, Integer> map = new HashMap<>();
        map.put(1, 31);
        if (leapYear) {
            map.put(2, 29);
        }
        else {
            map.put(2, 28);
        }
        map.put(3, 31);
        map.put(4, 30);
        map.put(5, 31);
        map.put(6, 30);
        map.put(7, 31);
        map.put(8, 31);
        map.put(9, 30);
        map.put(10, 31);
        map.put(11, 30);
        map.put(12, 31);
        String month = information[1];
        String day = information[2];
        if (month.equals("01")) {
            return Integer.parseInt(day);
        }
        int res1 = 0;
        for (int i = 1; i <= Integer.parseInt(month) - 1; i++) {
            res1 += map.get(i);
        }
        int res2 = Integer.parseInt(day);
        return res1 + res2;
    }
    private boolean isLeapYear(int year) {
        boolean leap = false;
        if (year % 4 == 0) {
            if (year % 100 == 0) {
                leap = year % 400 == 0;
            }
            else {
                leap = true;
            }
        }
        return leap;
    }
}
