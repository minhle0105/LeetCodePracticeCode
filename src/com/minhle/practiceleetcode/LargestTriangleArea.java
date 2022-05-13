package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class LargestTriangleArea {
    public double largestTriangleArea(int[][] points) {
        double maxArea = Double.MIN_VALUE;
        for (int i = 0; i < points.length - 2; i++) {
            for (int j = i + 1; j < points.length - 1; j++) {
                for (int k = j + 1; k < points.length; k++) {
                    boolean triangle = isTriangle(points[i], points[j], points[k]);
                    if (triangle) {
                        double area = calculateArea(points[i], points[j], points[k]);
                        maxArea = Math.max(area, maxArea);
                    }
                }
            }
        }
        return maxArea;
    }

    private double calculateDistance(int[] a, int[] b) {
        int x1 = a[0];
        int x2 = b[0];

        int y1 = a[1];
        int y2 = b[1];

        double first = Math.pow((y2 - y1), 2);
        double second = Math.pow((x2 - x1), 2);
        return Math.sqrt(first + second);
    }

    private boolean isTriangle(int[] a, int[] b, int[] c) {
        double ab = calculateDistance(a, b);
        double ac = calculateDistance(a, c);
        double bc = calculateDistance(b, c);
        boolean firstCase = ab + ac > bc;
        boolean secondCase = ab + bc > ac;
        boolean thirdCase = ac + bc > ab;
        return firstCase & secondCase & thirdCase;
    }

    private double calculateArea(int[] a, int[] b, int[] c) {
        double ab = calculateDistance(a, b);
        double ac = calculateDistance(a, c);
        double bc = calculateDistance(b, c);

        double halfPerimeter = (ab + ac + bc) / 2;
        double first = halfPerimeter - ab;
        double second = halfPerimeter - ac;
        double third = halfPerimeter - bc;
        return Math.sqrt(halfPerimeter * first * second * third);
    }

    @Test
    void failedTest() {
        int[][] points = {
                {35, -23}, {-12, -48}, {-34, -40}, {21, -25},
                {-35, -44}, {24, 1}, {16, -9}, {41, 4},
                {-36, -49}, {42, -49}, {-37, -20}, {-35, 11},
                {-2, -36}, {18, 21}, {18, 8}, {-24, 14},
                {-23, -11}, {-8, 44}, {-19, -3}, {0, -10},
                {-21, -4}, {23, 18}, {20, 11}, {-42, 24},
                {6, -19}
        };
        double expected = 3627.00000;
        double actual = largestTriangleArea(points);
        Assertions.assertTrue(Math.abs(expected - actual) <= Math.pow(10, -5));
    }
}
