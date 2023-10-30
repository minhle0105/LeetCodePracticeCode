package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.*;

public class IntegerToRoman {

    private void initializeHashMap(Map<Integer, String> map) {
        map.put(1, "I");
        map.put(4, "IV");
        map.put(5, "V");
        map.put(9, "IX");
        map.put(10, "X");
        map.put(40, "XL");
        map.put(50, "L");
        map.put(90, "XC");
        map.put(100, "C");
        map.put(400, "CD");
        map.put(500, "D");
        map.put(900, "CM");
        map.put(1000, "M");
    }
    public String intToRoman(int num) {
        Map<Integer, String> map = new HashMap<>();
        initializeHashMap(map);
        int[] nums = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
        StringBuilder roman = new StringBuilder();
        while (num != 0) {
            if (map.containsKey(num)) {
                roman.append(map.get(num));
                num -= num;
            }
            else {
                int largestSmallerElement = 1000;
                for (int i = 0; i < nums.length; i++) {
                    if (nums[i] > num) {
                        largestSmallerElement = nums[i - 1];
                        break;
                    }
                }
                roman.append(map.get(largestSmallerElement));
                num -= largestSmallerElement;
            }
        }
        return roman.toString();
    }

    @Test
    void test1() {
        int num = 3;
        Assertions.assertEquals("III", intToRoman(num));
    }

    @Test
    void test2() {
        int num = 58;
        Assertions.assertEquals("LVIII", intToRoman(num));
    }

    @Test
    void test3() {
        int num = 1994;
        Assertions.assertEquals("MCMXCIV", intToRoman(num));
    }

    @Test
    void test4() {
        int num = 1958;
        Assertions.assertEquals("MCMLVIII", intToRoman(num));
    }
}
