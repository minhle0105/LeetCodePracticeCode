package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class DecimalToHexa {
    static void converter(int x) {
        int remainder = x % 16;
        int ascii = 0;
        while (remainder != 0) {
            x /= 16;
            if (remainder < 10) {
                ascii = 48 + remainder;
            } else {
                ascii = 55 + remainder;
            }
            remainder = x % 16;
            System.out.println((char) ascii);
        }


    }

    public static void main(String[] args) {
        converter(2545);
    }
}
