package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class LargestOddNumberInString {
    public String largestOddNumber(String num) {
        for (int i = num.length() - 1; i >= 0; i--) {
            if (Integer.parseInt(String.valueOf(num.charAt(i))) % 2 != 0) {
                return num.substring(0, i+1);
            }
        }
        return "";
    }

    @Test
    void firstTest() {
        String num = "52";
        String expected = "5";
        String actual = largestOddNumber(num);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void secondTest() {
        String num = "4206";
        String expected = "";
        String actual = largestOddNumber(num);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void thirdTest() {
        String num = "35427";
        String expected = "35427";
        String actual = largestOddNumber(num);
        Assertions.assertEquals(expected, actual);
    }
}
