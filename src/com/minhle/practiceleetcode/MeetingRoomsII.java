package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.Comparator;
import java.util.PriorityQueue;

class Meeting {
    private int startTime;
    private int endTime;

    public Meeting(int startTime, int endTime) {
        this.startTime = startTime;
        this.endTime = endTime;
    }

    public int getStartTime() {
        return startTime;
    }

    public void setStartTime(int startTime) {
        this.startTime = startTime;
    }

    public int getEndTime() {
        return endTime;
    }

    public void setEndTime(int endTime) {
        this.endTime = endTime;
    }
}

public class MeetingRoomsII {
    public int minMeetingRooms(int[][] intervals) {
        int meetingRoom = 1;
        PriorityQueue<Meeting> heap = new PriorityQueue<>(new Comparator<Meeting>() {
            @Override
            public int compare(Meeting o1, Meeting o2) {
                if (o1.getStartTime() == o2.getStartTime()) {
                    return Integer.compare(o1.getEndTime(), o2.getEndTime());
                }
                return Integer.compare(o1.getStartTime(), o2.getStartTime());
            }
        });
        for (int[] meeting : intervals) {
            Meeting meeting1 = new Meeting(meeting[0], meeting[1]);
            heap.add(meeting1);
        }
        while (heap.size() > 1) {
            Meeting thisMeeting = heap.remove();
            if (thisMeeting.getEndTime() > heap.peek().getStartTime()) {
                meetingRoom++;
            }
        }
        return meetingRoom;
    }

    @Test
    void firstTest() {
        int[][] intervals = {{0,30},{5,10},{15,20}};
        int expected = 2;
        int actual = minMeetingRooms(intervals);
        Assertions.assertEquals(expected, actual);
    }
    @Test
    void secondTest() {
        int[][] intervals = {{7,10},{2,4}};
        int expected = 1;
        int actual = minMeetingRooms(intervals);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void failTest() {
        int[][] intervals = {{9,10},{4,9},{4,17}};
        int expected = 2;
        int actual = minMeetingRooms(intervals);
        Assertions.assertEquals(expected, actual);
    }
}

