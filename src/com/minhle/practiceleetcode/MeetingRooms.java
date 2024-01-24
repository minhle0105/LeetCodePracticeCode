package com.minhle.practiceleetcode;

import java.util.Arrays;

public class MeetingRooms {
    public boolean canAttendMeetings(int[][] intervals) {
        if (intervals.length == 0) {
            return true;
        }
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
        for (int i = 0; i < intervals.length - 1; i++) {
            int[] first = intervals[i];
            int[] second = intervals[i + 1];
            if (first[1] > second[0]) {
                return false;
            }
        }
        return true;
    }
}
