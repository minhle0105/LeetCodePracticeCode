package com.minhle.practiceleetcode;

import java.util.*;
public class DesignHitCounter {
    static class Hit implements Comparable<Hit> {
        int time;
        public Hit (int time) {
            this.time = time;
        }
        @Override
        public int compareTo(Hit o) {
            return Integer.compare(o.time, this.time);
        }
    }

    static class HitCounter {

        PriorityQueue<Hit> queue;

        public HitCounter() {
            queue = new PriorityQueue<>();
        }

        public void hit(int timestamp) {
            this.queue.add(new Hit(timestamp));
        }

        public int getHits(int timestamp) {
            int res = 0;
            List<Hit> removed = new ArrayList<>();
            while (!queue.isEmpty() && queue.peek().time > timestamp - 300) {
                res++;
                removed.add(queue.remove());
            }
            for (Hit hit : removed) {
                this.queue.add(hit);
            }

            return res;
        }
    }
}
