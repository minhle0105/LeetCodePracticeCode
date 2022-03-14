package com.minhle.practiceleetcode;

import java.util.PriorityQueue;

public class SeatReservationManager {
    private int[] seats;
    private PriorityQueue<Integer> heap;

    public SeatReservationManager(int n) {
        heap = new PriorityQueue<>();
        seats = new int[n + 1];
        for (int i = 1; i < seats.length; i++) {
            heap.add(i);
        }
    }

    public int reserve() {
        if (heap.isEmpty()) {
            return -1;
        }
        int minSeat = heap.remove();
        seats[minSeat] = 1;
        return minSeat;
    }

    public void unreserve(int seatNumber) {
        seats[seatNumber] = 0;
        heap.add(seatNumber);
    }
}
