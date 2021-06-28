package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.math.BigInteger;

public class AddString {
    public String addStrings(String num1, String num2) {
        if (num1.length() < 1 | num2.length() < 1 | num1.length() > Math.pow(10,4) | num2.length() > Math.pow(10,4)) {
            return "";
        }
        BigInteger a = new BigInteger(num1);
        BigInteger b = new BigInteger(num2);
        BigInteger sum = a.add(b);
        return sum.toString();
    }

    @Test
    void firstTest() {
        String expected = "134";
        String actual = addStrings("11", "123");
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void failedTest() {
        String expected = "10405985147604178950";
        String actual = addStrings("3876620623801494171", "6529364523802684779");
        Assertions.assertEquals(expected, actual);
    }
}
