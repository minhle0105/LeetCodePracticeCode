package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.LinkedList;
import java.util.List;

public class BaseballGame {

    // Integer -> record new score
    // + record new score that is sum of two previous score
    // D record new score that is double of the previous score
    // C remove the previous score
    public int calPoints(String[] ops) {
        int currentSum = 0;
        List<Integer> scores = new LinkedList<>();
        int n = 0;
        for (String o : ops) {
            try {
                int oInt = Integer.parseInt(o);
                currentSum += oInt;
                scores.add(oInt);
                n++;
            }
            catch (Exception e) {
                switch (o) {
                    case "+":
                        int prev1 = scores.get(n - 1);
                        int prev2 = scores.get(n - 2);
                        scores.add(prev1 + prev2);
                        currentSum += prev1 + prev2;
                        n++;
                        break;
                    case "D":
                        int prev = scores.get(n - 1);
                        scores.add(prev * 2);
                        currentSum += prev * 2;
                        n++;
                        break;
                    case "C":
                        prev = scores.remove(n - 1);
                        currentSum -= prev;
                        n--;
                        break;
                }
            }
        }
        return currentSum;
    }

    @Test
    void test1() {
        String[] ops = {"5","2","C","D","+"};
        int expected = 30;
        int actual = calPoints(ops);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void test2() {
        String[] ops = {"5","-2","4","C","D","9","+","+"};
        int expected = 27;
        int actual = calPoints(ops);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void test3() {
        String[] ops = {"1"};
        int expected = 1;
        int actual = calPoints(ops);
        Assertions.assertEquals(expected, actual);
    }
}
