package com.minhle.practiceleetcode;

import java.util.LinkedList;

public class NumberOfRecentCalls {

    static class RecentCounter {

        LinkedList<Integer> calls;

        public RecentCounter() {
            this.calls = new LinkedList<>();
        }

        public int ping(int t) {
            calls.addLast(t);
            while (this.calls.getFirst() < t - 3000) {
                this.calls.removeFirst();
            }
            return this.calls.size();
        }
    }
}
