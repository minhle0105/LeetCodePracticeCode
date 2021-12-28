package com.minhle.practiceleetcode;

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
                    case "+" -> {
                        int prev1 = scores.get(n - 1);
                        int prev2 = scores.get(n - 2);
                        scores.add(prev1 + prev2);
                        currentSum += prev1 + prev2;
                        n++;
                    }
                    case "D" -> {
                        int prev = scores.get(n - 1);
                        scores.add(prev * 2);
                        currentSum += prev * 2;
                        n++;
                    }
                    case "C" -> {
                        int prev = scores.remove(n - 1);
                        currentSum -= prev;
                        n--;
                    }
                }
            }
        }
        return currentSum;
    }
}
