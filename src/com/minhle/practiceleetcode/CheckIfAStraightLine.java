package com.minhle.practiceleetcode;

public class CheckIfAStraightLine {
    public boolean checkStraightLine(int[][] coordinates) {
        int[] point1 = coordinates[0];
        int[] point2 = coordinates[1];
        double slope = getSlope(point1, point2);
        for (int i = 1; i < coordinates.length - 1; i++) {
            int[] nextPoint1 = coordinates[i];
            int[] nextPoint2 = coordinates[i + 1];
            double thisSlope = getSlope(nextPoint1, nextPoint2);
            if (thisSlope != slope) {
                return false;
            }
        }
        return true;

    }

    private double getSlope(int[] point1, int[] point2) {
        int x1 = point1[0];
        int y1 = point1[1];
        int x2 = point2[0];
        int y2 = point2[1];
        if (x1 == x2) {
            return -1;
        }
        if (y1 == y2) {
            return 0;
        }
        return ((double) (y2 - y1)) / (x2 - x1);
    }
}
