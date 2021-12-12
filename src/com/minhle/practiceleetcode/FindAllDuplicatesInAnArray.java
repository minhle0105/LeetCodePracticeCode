package com.minhle.practiceleetcode;

import java.util.ArrayList;
import java.util.List;

public class FindAllDuplicatesInAnArray {
    public List<Integer> findDuplicates(int[] nums) {
        List<Integer> result = new ArrayList<>();
        int[] visited = new int[nums.length + 1];
        for (int i : nums) {
            if (visited[i] == 0) {
                visited[i] = 1;
            }
            else {
                result.add(i);
            }
        }
        return result;
    }
}
