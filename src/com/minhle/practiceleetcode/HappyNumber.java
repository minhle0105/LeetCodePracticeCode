package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;

public class HappyNumber {
    public boolean isHappy(int n) {
        String xString = Integer.toString(n);
        int result = 0;
        ArrayList<Integer> existedSum = new ArrayList<>();
        boolean isAHappyNumber = false;

        while (true) {
            result = 0;
            for (int i = 0; i < xString.length(); i++) {
                result += Math.pow(Integer.parseInt(String.valueOf(xString.charAt(i))), 2);
            }
            if (existedSum.contains(result)) {
                break;
            }
            if (result == 1) {
                isAHappyNumber = true;
                break;
            }
            existedSum.add(result);
            xString = Integer.toString(result);
        }
        return isAHappyNumber;
    }

    @Test
    void firstTest() {
        boolean expected = true;
        boolean actual = isHappy(19);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void secondTest() {
        boolean actual = isHappy(2);
        Assertions.assertFalse(actual);
    }

    @Test
    void lastTest() {
        boolean actual = isHappy(29);
        Assertions.assertFalse(actual);
    }
}
