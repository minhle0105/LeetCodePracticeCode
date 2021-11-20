package com.minhle.practiceleetcode;

import java.util.Stack;

public class MinStack {

    private final Stack<Integer> stack;
    private final Stack<Integer> minValues;

    /** initialize your data structure here. */
    public MinStack() {
        this.stack = new Stack<>();
        this.minValues = new Stack<>();
    }

    public void push(int val) {
        if (this.minValues.isEmpty() || val <= this.minValues.peek()) {
            this.minValues.push(val);
        }
        this.stack.add(val);
    }

    public void pop() {
        if (this.stack.peek().equals(this.minValues.peek())) {
            this.minValues.pop();
        }
        this.stack.pop();
    }

    public int top() {
        return this.stack.peek();
    }

    public int getMin() {
        return this.minValues.peek();
    }
}
