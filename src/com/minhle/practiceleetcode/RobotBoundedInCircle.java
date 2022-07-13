package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class RobotBoundedInCircle {

    int[] vector;
    int[] position;

    public boolean isRobotBounded(String instructions) {
        vector = new int[]{0, 1};
        position = new int[]{0, 0};
        for (char instruction : instructions.toCharArray()) {
            if (instruction == 'G') {
                position[0] += vector[0];
                position[1] += vector[1];
            }
            else if (instruction == 'L') {
                turnLeft();
            }
            else {
                turnRight();
            }
        }
        boolean samePosition = position[0] == 0 & position[1] == 0;
        boolean sameDirection = vector[0] != 0 | vector[1] != 1;
        return (samePosition) | (sameDirection);
    }

    private void turnLeft() {
        int temp = vector[0];
        vector[0] = -1 * vector[1];
        vector[1] = temp;
    }

    private void turnRight() {
        int temp = vector[0];
        vector[0] = vector[1];
        vector[1] = -1 * temp;
    }

    @Test
    void test1() {
        String directions = "GGLLGG";
        Assertions.assertTrue(isRobotBounded(directions));
    }

    @Test
    void test2() {
        String directions = "GG";
        Assertions.assertFalse(isRobotBounded(directions));
    }

    @Test
    void test3() {
        String directions = "GL";
        Assertions.assertTrue(isRobotBounded(directions));
    }

}
