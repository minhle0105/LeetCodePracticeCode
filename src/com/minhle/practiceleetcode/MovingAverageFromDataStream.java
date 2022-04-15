package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.*;

public class MovingAverageFromDataStream {
    LinkedList<Integer> data;
    int windowSize;
    int currentWindowSum;

    public MovingAverageFromDataStream(int size) {
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
