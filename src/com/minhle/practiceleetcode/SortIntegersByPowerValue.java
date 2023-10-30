package com.minhle.practiceleetcode;

import java.util.Arrays;

public class SortIntegersByPowerValue {
    static class Number implements Comparable<Number> {
        int val;
        int step;

        public Number(int val) {
            this.val = val;
            calculateStep();
        }
        private void calculateStep() {
            int current = val;
            int count = 0;
            while (current != 1) {
                if (current % 2 == 0) {
                    current /= 2;
                }
                else {
                    current *= 3;
                    current++;
                }
                count++;
            }
            this.step = count;
        }
        @Override
        public int compareTo(Number o) {
            if (this.step == o.step) {
                return Integer.compare(this.val, o.val);
            }
            return Integer.compare(this.step, o.step);
        }
    }

    public int getKth(int lo, int hi, int k) {
        Number[] numbers = new Number[hi - lo + 1];
        int ind = 0;
        for (int i = lo; i <= hi; i++) {
            numbers[ind++] = new Number(i);
        }
        Arrays.sort(numbers);
        return numbers[k - 1].val;
    }
}
