package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Test;

public class TrappingRainWater {
    int[] maxLeft;
    int[] maxRight;

    int[] minLeftRight;
    private void findMaxArrays(int[] input) {
        maxLeft = new int[input.length];
        maxRight = new int[input.length];
        minLeftRight = new int[input.length];
        for (int i = 1; i < maxLeft.length; i++) {
            maxLeft[i] = Math.max(maxLeft[i - 1], input[i - 1]);
        }
        for (int i = maxRight.length - 2; i >= 0; i--) {
            maxRight[i] = Math.max(maxRight[i + 1], input[i + 1]);
        }
        for (int i = 0; i < minLeftRight.length; i++) {
            minLeftRight[i] = Math.min(maxLeft[i], maxRight[i]);
        }
    }

    private int calculateTotalTrappedWater(int[] input) {
        findMaxArrays(input);
        int[] totalTrappedWater = new int[input.length];
        for (int i = 0; i < totalTrappedWater.length; i++) {
            int water = minLeftRight[i] - input[i];
            totalTrappedWater[i] = Math.max(water, 0);
        }
        int sum = 0;
        for (int water : totalTrappedWater) {
            sum += water;
        }
        return sum;
    }

    @Test
    void test1() {
        int[] input = {0,1,0,2,1,0,1,3,2,1,2,1};
        calculateTotalTrappedWater(input);
    }
}
