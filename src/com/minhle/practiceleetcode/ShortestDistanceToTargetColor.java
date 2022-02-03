package com.minhle.practiceleetcode;

import java.util.*;

public class ShortestDistanceToTargetColor {
    public List<Integer> shortestDistanceColor(int[] colors, int[][] queries) {
        List<Integer> results = new ArrayList<>();
        for (int[] query : queries) {
            int index = query[0];
            int target = query[1];
            int distance = getDistance(colors, index, target);
            if (distance == Integer.MAX_VALUE) {
                results.add(-1);
            }
            else {
                results.add(distance);
            }
        }
        return results;
    }

    private int getDistance(int[] colors, int index, int target) {
        if (colors[index] == target) {
            return 0;
        }

        int firstPointer = index - 1;
        int secondPointer = index + 1;
        int firstDistance = Integer.MAX_VALUE;
        int secondDistance = Integer.MAX_VALUE;
        while (firstPointer >= 0) {
            if (colors[firstPointer] == target) {
                firstDistance = Math.abs(index - firstPointer);
                break;
            }
            else {
                firstPointer --;
            }
        }
        while (secondPointer < colors.length) {
            if (colors[secondPointer] == target) {
                secondDistance = Math.abs(index - secondPointer);
                break;
            }
            else {
                secondPointer++;
            }
        }
        return Math.min(firstDistance, secondDistance);
    }
}
