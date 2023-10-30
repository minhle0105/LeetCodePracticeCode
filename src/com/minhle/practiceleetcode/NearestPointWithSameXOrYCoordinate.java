package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.HashMap;
import java.util.Map;

public class NearestPointWithSameXOrYCoordinate {
    public int nearestValidPoint(int x, int y, int[][] points) {
        Map<Integer, int[]> qualifiedPointsFirstFilers = filter1(x, y, points);
        double smallestDistance = Double.MAX_VALUE;
        int smallestIndex = -1;
        int[] currentPoint = new int[]{x, y};

        for (Integer i : qualifiedPointsFirstFilers.keySet()) {
            double thisDistance = calculateManhattanDistance(currentPoint, qualifiedPointsFirstFilers.get(i));
            if (thisDistance < smallestDistance) {
                smallestDistance = thisDistance;
                smallestIndex = i;
            }
        }
        return smallestIndex;
    }

    private Map<Integer, int[]> filter1(int x, int y, int[][] points) {
        Map<Integer, int[]> qualifiedPoints = new HashMap<>();
        for (int i = 0; i < points.length; i++) {
            int[] point = points[i];
            if (x == point[0] | y == point[1]) {
                qualifiedPoints.put(i, point);
            }
        }
        return qualifiedPoints;
    }

    private double calculateManhattanDistance(int[] point1, int[] point2) {
        int x1 = point1[0];
        int y1 = point1[1];
        int x2 = point2[0];
        int y2 = point2[1];
        return Math.abs(x1 - x2) + Math.abs(y1 - y2);
    }

    @Test
    void test1() {
        int x = 3;
        int y = 4;
        int[][] points = {{1,2},{3,1},{2,4},{2,3},{4,4}};
        int expected = 2;
        int actual = nearestValidPoint(x, y, points);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void test2() {
        int x = 3;
        int y = 4;
        int[][] points = {{3,4}};
        int expected = 0;
        int actual = nearestValidPoint(x, y, points);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void test3() {
        int x = 3;
        int y = 4;
        int[][] points = {{2,3}};
        int expected = -1;
        int actual = nearestValidPoint(x, y, points);
        Assertions.assertEquals(expected, actual);
    }
}
