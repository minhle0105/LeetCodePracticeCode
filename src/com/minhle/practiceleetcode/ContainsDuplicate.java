package com.minhle.practiceleetcode;

import java.util.HashMap;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

public class ContainsDuplicate {
    public boolean containsDuplicate(int[] nums) {
        HashMap<Integer, Integer> hashmap = new HashMap<>();
        for (int i : nums) {
            if (!hashmap.containsKey(i)) {
                hashmap.put(i,1);
            }
            else {
                return true;
            }
        }
        return false;
    }

    @Test
    void firstTest(){
        int[] nums = new int[]{1,2,3,1};
        assertTrue(containsDuplicate(nums));
    }

    @Test
    void secondTest() {
        int[] nums = new int[]{1,2,3,4};
        assertFalse(containsDuplicate(nums));
    }

    @Test
    void thirdTest() {
        int[] nums = new int[]{1,1,1,3,3,4,3,2,4,2};
        assertTrue(containsDuplicate(nums));
    }

}
