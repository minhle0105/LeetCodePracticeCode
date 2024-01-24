package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.LinkedList;
import java.util.Queue;

public class RemoveElement {
    public int remove(int[] nums, int val) {
        Queue<Integer> queue = new LinkedList<>();
        int count = 0;
        for (int i : nums) {
            queue.add(i);
        }
        while (!queue.isEmpty()) {
            if (queue.peek() != val) {
                nums[count++] = queue.remove();
            }
            else {
                queue.remove();
            }
        }
        return count;
    }

    @Test
    void firstTest() {
        int[] nums = {3,2,2,3};
        int val = 3;
        int expected = 2;
        int actual = remove(nums, val);
        Assertions.assertEquals(expected, actual);
    }
}
