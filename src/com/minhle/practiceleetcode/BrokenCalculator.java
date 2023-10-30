package com.minhle.practiceleetcode;

public class BrokenCalculator {
    public int brokenCalc(int startValue, int target) {
        int step = 0;
        while (target > startValue) {
            step++;
            if (target % 2 == 1) {
                target++;
            }
            else {
                target /= 2;
            }
        }
        return step + startValue - target;
    }
}
