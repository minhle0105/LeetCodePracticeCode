package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.LinkedList;
import java.util.List;
import java.util.Stack;

public class BaseballGame {

    // Integer -> record new score
    // + record new score that is sum of two previous score
    // D record new score that is double of the previous score
    // C remove the previous score
    public int calPoints(String[] ops) {
        int currentSum = 0;
        Stack<Integer> scores = new Stack<>();
        for (String o : ops) {
            if (o.equals("+")) {
                int[] temp = {scores.pop(), scores.pop()};
                int sum = temp[0] + temp[1];
                scores.push(temp[1]);
                scores.push(temp[0]);
                scores.push(sum);
                currentSum += sum;
            }
            else if (o.equals("C")) {
                int prev = scores.pop();
                currentSum -= prev;
            }
            else if (o.equals("D")) {
                int prev = scores.peek();
                scores.add(prev * 2);
                currentSum += prev * 2;
            }
            else {
                int oInt = Integer.parseInt(o);
                currentSum += oInt;
                scores.push(oInt);
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
