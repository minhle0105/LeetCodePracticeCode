package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class DecimalToHexa {
    static void converter(int x) {
        int remainder = x % 16;
        int xCopy = x;
        int remainderCopy = xCopy % 16;
        int r = remainderCopy;
        int ascii = 0;
        int iterationCount = 0;
        while (remainder != 0) {
            x /= 16;
            if (remainder < 10) {
                ascii = 48 + remainder;
            } else {
                ascii = 55 + remainder;
            }
            remainder = x % 16;
            iterationCount ++;
        }
        int printCount = 0;
        while (printCount <= iterationCount) {
            while (remainderCopy != 0) {
                xCopy /= 16;
                if (remainderCopy < 10) {
                    ascii = 48 + remainderCopy;
                } else {
                    ascii = 55 + remainderCopy;
                }
                remainderCopy = xCopy % 16;
                for (int count = iterationCount; count >= 0; count-- ) {
                    if (count - printCount >= 0) {
                        System.out.print((char) ascii);
                        printCount++;
                    }
                }

            }
        }


    }

    public static void main(String[] args) {
        converter(2545);
    }
}
