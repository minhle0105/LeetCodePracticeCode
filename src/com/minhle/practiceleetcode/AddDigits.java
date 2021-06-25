package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class AddDigits {
    public int addDigits(int num) {
        int result;
        while (true) {
            result = 0;
            result += num % 10;
            result += num / 10;
            if (result / 10 == 0) {
                break;
            }
            num = result;
        }
        return result;
    }

    @Test
    void firstTest() {
        int expected = 2;
        int actual = addDigits(38);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void secondTest() {
        int expected = 0;
        int actual = addDigits(0);
        Assertions.assertEquals(expected, actual);
    }
}
