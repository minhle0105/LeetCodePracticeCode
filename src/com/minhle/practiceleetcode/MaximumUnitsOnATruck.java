package com.minhle.practiceleetcode;

import java.util.Arrays;

public class MaximumUnitsOnATruck {
    static class Box implements Comparable<Box> {
        int type;
        int numberOfBox;
        int numberOfUnit;

        @Override
        public int compareTo(Box o) {
            return Integer.compare(o.numberOfUnit, this.numberOfUnit);
        }

        public Box (int type, int numberOfBox, int numberOfUnit) {
            this.type = type;
            this.numberOfBox = numberOfBox;
            this.numberOfUnit = numberOfUnit;
        }

    }
    public int maximumUnits(int[][] boxTypes, int truckSize) {
        Box[] boxes = new Box[boxTypes.length];
        for (int i = 0; i < boxTypes.length; i++) {
            Box box = new Box(i, boxTypes[i][0], boxTypes[i][1]);
            boxes[i] = box;
        }
        Arrays.sort(boxes);
        int unitPlaced = 0;
        int boxPlaced = 0;
        int i = 0;
        while (i < boxTypes.length && boxPlaced < truckSize) {
            unitPlaced += boxes[i].numberOfBox * boxes[i].numberOfUnit;
            boxPlaced += boxes[i].numberOfBox;
            while (boxPlaced > truckSize) {
                unitPlaced -= boxes[i].numberOfUnit;
                boxPlaced--;
            }
            i++;
        }
        return unitPlaced;
    }
}
