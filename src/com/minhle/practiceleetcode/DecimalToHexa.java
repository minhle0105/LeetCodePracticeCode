package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class DecimalToHexa {
    String converter(int x) {
        int remainder = x % 16;
        StringBuilder hexa = new StringBuilder();
        int ascii = 0;
        while (remainder != 0) {
            x /= 16;
            if (remainder < 10) {
                ascii = 48 + remainder;
            }
            else {
                ascii = 55 + remainder;
            }
            hexa.append((char) ascii);
            remainder = x % 16;
        }
        StringBuilder result = new StringBuilder();
        for (int i = hexa.toString().length() - 1; i >= 0; i--) {
            result.append(hexa.toString().charAt(i));
        }
        return result.toString();
    }

    @Test
    void firstTest() {
        int x = 2545;
        String expected = "9F1";
        String actual = converter(x);
        Assertions.assertEquals(expected, actual);
    }
}
