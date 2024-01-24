package com.minhle.practiceleetcode;

import java.util.LinkedList;
import java.util.Queue;

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
}
