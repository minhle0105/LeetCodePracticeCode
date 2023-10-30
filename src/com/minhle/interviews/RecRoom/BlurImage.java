package com.minhle.interviews.RecRoom;

public class BlurImage {
    private float[][] blur (float[] pixels, int width, int height, int blurRadius) {
        float[][] image = new float[height][width];
        int ind = 0;
        for (int r = 0; r < height; r++) {
            for (int c = 0; c < width; c++) {
                image[r][c] = pixels[ind++];
            }
        }

        float[][] pixelSums = new float[height][width];
        int[][] validSurroundingCells = new int[height][width];

        for (int r = 0; r < height; r++) {
            for (int c = 0; c < width; c++) {
                float pixelSum = image[r][c];
                int validCell = 1;
                for (int r1 = r - blurRadius; r1 <= r + blurRadius; r1 ++) {
                    for (int c1 = c - blurRadius; c1 <= c + blurRadius; c1++) {
                        if (r1 < 0 || r1 == height || c1 < 0 || c1 == width || r1 == r || c1 == c) {
                            continue;
                        }
                        pixelSum += image[r1][c1];
                        validCell++;
                    }
                }
                pixelSums[r][c] = pixelSum;
                validSurroundingCells[r][c] = validCell;
            }
        }

        float[][] res = new float[height][width];
        for (int r = 0; r < height; r++) {
            for (int c = 0; c < width; c++) {
                res[r][c] = pixelSums[r][c] / validSurroundingCells[r][c];
            }
        }
        return res;
    }
}
