package com.minhle.practiceleetcode;

import java.util.HashMap;
import java.util.Map;

public class LoggerRateLimiter {
    Map<String, Integer> rate;

    public LoggerRateLimiter() {
        rate = new HashMap<>();
    }

    public boolean shouldPrintMessage(int timestamp, String message) {
        if (!rate.containsKey(message)) {
            rate.put(message, timestamp);
            return true;
        }
        if (rate.containsKey(message)) {
            if (timestamp >= rate.get(message) + 10) {
                rate.put(message, timestamp);
                return true;
            }
        }
        return false;
    }
}
