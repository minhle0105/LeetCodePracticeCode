package com.minhle.practiceleetcode;

public class DesignParkingSystem {
    int bigCars;
    int mediumCars;
    int smallCars;
    int bigLimit;
    int mediumLimit;
    int smallLimit;

    public DesignParkingSystem(int big, int medium, int small) {
        this.bigCars = 0;
        this.mediumCars = 0;
        this.smallCars = 0;
        this.bigLimit = big;
        this.mediumLimit = medium;
        this.smallLimit = small;
    }

    public boolean addCar(int carType) {
        if (carType == 1) {
            if (this.bigCars < this.bigLimit) {
                this.bigCars++;
                return true;
            }
            else {
                return false;
            }
        }
        else if (carType == 2) {
            if (this.mediumCars < this.mediumLimit) {
                this.mediumCars++;
                return true;
            }
            else {
                return false;
            }
        }
        else {
            if (this.smallCars < this.smallLimit) {
                this.smallCars++;
                return true;
            }
            else {
                return false;
            }
        }
    }
}
