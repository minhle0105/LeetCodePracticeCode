package com.minhle.practiceleetcode;

import java.util.Arrays;

public class FindKthLargestIntegerInArray {
    static class StringVal implements Comparable<StringVal> {
        String o1;

        public StringVal(String s) {
            this.o1 = s;
        }

        public int compareTo(StringVal o) {
            String o2 = o.o1;
            if (o1.length() > o2.length()) return -1;
            if (o1.length() < o2.length()) return 1;
            else {
                for (int i = 0; i < o1.length(); i++) {
                    int o1Int = Integer.parseInt(String.valueOf(o1.charAt(i)));
                    int o2Int = Integer.parseInt(String.valueOf(o2.charAt(i)));
                    if (o1Int != o2Int) {
                        return Integer.compare(o2Int, o1Int);
                    }
                }
            }
            return 0;
        }
    }
    public String kthLargestNumber(String[] nums, int k) {
        StringVal[] stringVals = new StringVal[nums.length];
        for (int i = 0; i < nums.length; i++) {
            stringVals[i] = new StringVal(nums[i]);
        }
        Arrays.sort(stringVals);
        return stringVals[k - 1].o1;
    }
}
