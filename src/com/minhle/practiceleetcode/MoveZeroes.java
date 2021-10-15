package com.minhle.practiceleetcode;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class MoveZeroes {
    public static void move(int[] nums) {
        int counterNums = 0;
        Queue<Integer> queue = new LinkedList<>();
        for (int num : nums) {
            queue.add(num);
        }
        while (!queue.isEmpty()) {
            if (queue.peek() != 0) {
                nums[counterNums++] = queue.remove();
            }
            else {
                queue.remove();
            }
        }
        while (counterNums < nums.length) {
            nums[counterNums++] = 0;
        }
    }

    public static void main(String[] args) {
        int[] nums = {0, 1, 0, 3, 12};
        move(nums);
        System.out.println(Arrays.toString(nums));
    }
}
