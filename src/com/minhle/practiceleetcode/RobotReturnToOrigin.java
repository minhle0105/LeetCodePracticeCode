package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class RobotReturnToOrigin {
    int[] currentPosition;
    public boolean judgeCircle(String moves) {
        currentPosition = new int[]{0,0};
        for (char c : moves.toCharArray()) {
            switch (c) {
                case 'L':
                    goLeft();
                    break;
                case 'U':
                    goUp();
                    break;
                case 'D':
                    goDown();
                    break;
                case 'R':
                    goRight();
                    break;
                default:
            }
        }
        return currentPosition[0] == 0 && currentPosition[1] == 0;
    }
    private void goLeft() {
        currentPosition[1]--;
    }
    private void goRight() {
        currentPosition[1]++;
    }
    private void goUp() {
        currentPosition[0]++;
    }
    private void goDown() {
        currentPosition[0]--;
    }

    @Test
    void test1() {
        String moves = "UD";
        Assertions.assertTrue(judgeCircle(moves));
    }
}
