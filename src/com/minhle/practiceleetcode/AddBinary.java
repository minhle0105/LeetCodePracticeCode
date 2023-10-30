package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class AddBinary {
    public String addBinary(String a, String b) {
        StringBuilder result = new StringBuilder();
        int currentDigitA = a.length() - 1;
        int currentDigitB = b.length() - 1;
        int carryNumber = 0;
        while (currentDigitA >= 0 || currentDigitB >= 0) {
            int sum = carryNumber;
            if (currentDigitA >= 0) {
                sum += Integer.parseInt(String.valueOf(a.charAt(currentDigitA)));
            }
            if (currentDigitB >= 0) {
                sum += Integer.parseInt(String.valueOf(b.charAt(currentDigitB)));
            }
            result.append(sum%2);
            carryNumber = sum / 2;
            currentDigitA --;
            currentDigitB --;
        }
        if (carryNumber != 0) {
            result.append(carryNumber);
        }
        return result.reverse().toString();
    }

    @Test
    void firstTest() {
        String expected = "100";
        String actual = addBinary("11", "1");
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void secondTest() {
        String expected = "10101";
        String actual = addBinary("1010", "1011");
        Assertions.assertEquals(expected, actual);
    }
}
