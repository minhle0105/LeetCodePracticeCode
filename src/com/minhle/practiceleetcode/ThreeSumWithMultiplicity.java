package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ThreeSumWithMultiplicity {
    public int threeSumMulti(int[] arr, int target) {
        long count = 0;
        Arrays.sort(arr);
        List<int[]> res = new ArrayList<>();
        int n = arr.length - 1;
        for (int i = 0; i < arr.length; i++) {
            int left = i + 1;
            int right = n;
            while (left < right) {
                int sum = arr[i] + arr[left] + arr[right];
                if (sum == target) {
                    res.add(new int[]{arr[i], arr[left], arr[right]});
                    left++;
                }
                else if (sum < target) {
                    left++;
                }
                else {
                    right --;
                }
            }
        }
        return (int) (count % ((Math.pow(10, 9)) + 7));
    }

    @Test
    void test1() {
        int[] nums = {1,1,2,2,3,3,4,4,5,5};
        int target = 8;
        Assertions.assertEquals(20, threeSumMulti(nums, target));
    }
}
