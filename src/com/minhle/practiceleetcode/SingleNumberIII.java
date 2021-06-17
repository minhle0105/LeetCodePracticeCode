package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.HashMap;

public class SingleNumberIII {
    public static int[] singleNumber(int[] nums) {
        boolean firstDomainCondition = 2 <= nums.length && nums.length <= 3 * Math.pow(10,4);
        if (!firstDomainCondition) {
            return new int[2];
        }
        HashMap<Integer, Integer> hashMap = new HashMap<>();

        for (int num : nums) {
            if (num < Math.pow(-2, 31) || num > Math.pow(2,31) - 1) {
                return new int[2];
            }
            if (!hashMap.containsKey(num)) {
                hashMap.put(num, 1);
            } else {
                hashMap.put(num, hashMap.get(num) + 1);
            }
        }

        int[] results = new int[2];
        int count = 0;
        for (int num : nums) {
            if (hashMap.get(num) == 1) {
                results[count++] = num;
            }
        }
        return results;
    }

    public static void main(String[] args) {
        int[] nums = {1,1,0,-2147483648};
        System.out.println(Arrays.toString(singleNumber(nums)));
    }
}
