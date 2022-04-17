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
}
