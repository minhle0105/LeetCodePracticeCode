package com.minhle.practiceleetcode;

public class RobotReturnToOrigin {
    public boolean judgeCircle(String moves) {
        int[] currentPosition = {0,0};
        for (char c : moves.toCharArray()) {
            switch (c) {
                case 'L':
                    currentPosition[1]--;
                    break;
                case 'U':
                    currentPosition[0]--;
                    break;
                case 'D':
                    currentPosition[0]++;
                    break;
                case 'R':
                    currentPosition[1]++;
                    break;
                default:
            }
        }
        return currentPosition[0] == 0 && currentPosition[1] == 0;
    }
}
