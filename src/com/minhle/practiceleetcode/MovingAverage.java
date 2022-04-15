package com.minhle.practiceleetcode;

import java.util.*;

public class MovingAverage {
    LinkedList<Integer> data;
    int windowSize;
    int currentWindowSum;

    public MovingAverage(int size) {
        data = new LinkedList<>();
        currentWindowSum = 0;
        windowSize = size;
    }

    public double next(int val) {
        if (data.size() == windowSize) {
            currentWindowSum += val;
            currentWindowSum -= data.get(0);
            data.removeFirst();
        } else {
            currentWindowSum += val;
        }
        data.add(val);
        return ((double) currentWindowSum) / data.size();
    }
}
