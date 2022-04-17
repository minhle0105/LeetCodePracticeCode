package com.minhle.practiceleetcode;
import java.util.*;

public class DesignBrowserHistory {
    String homepage;
    String currentPage;
    Stack<String> backward;
    Stack<String> forward;

    public DesignBrowserHistory(String homepage) {
        this.homepage = homepage;
        currentPage = homepage;
        backward = new Stack<>();
        forward = new Stack<>();

    }

    public void visit(String url) {
        backward.push(currentPage);
        currentPage = url;
        forward = new Stack<>();
    }

    public String back(int steps) {
        forward.push(currentPage);
        int limit = 0;
        limit = Math.min(steps - 1, backward.size());
        for (int i = 0; i < limit; i++) {
            forward.push(backward.pop());
        }
        try {
            currentPage = backward.pop();
        }
        catch (Exception e) {
            currentPage = forward.pop();
        }
        return currentPage;
    }

    public String forward(int steps) {
        backward.push(currentPage);
        int limit = Math.min(steps - 1, forward.size());
        for (int i = 0; i < limit; i++) {
            backward.push(forward.pop());
        }
        try {
            currentPage = forward.pop();
        }
        catch (Exception e) {
            currentPage = backward.pop();
        }
        return currentPage;
    }

//    ["BrowserHistory","visit","visit","visit","back","back","forward","visit","forward","back","back"]
//            [["leetcode.com"],["google.com"],["facebook.com"],["youtube.com"],[1],[1],[1],["linkedin.com"],[2],[2],[7]]


    // leetcode -> google -> facebook -> youtube
    public static void main(String[] args) {
        DesignBrowserHistory browserHistory = new DesignBrowserHistory("leetcode.com");
        browserHistory.visit("google.com");
        browserHistory.visit("facebook.com");
        browserHistory.visit("youtube.com");
        System.out.println(browserHistory.back(1));
        System.out.println(browserHistory.back(1));
        System.out.println(browserHistory.forward(1));
        browserHistory.visit("linkedin.com");
        System.out.println(browserHistory.forward(2));
        System.out.println(browserHistory.back(2));
        System.out.println(browserHistory.back(7));
    }
}
