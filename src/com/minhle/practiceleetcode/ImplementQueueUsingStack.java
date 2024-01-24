package com.minhle.practiceleetcode;

import java.util.Stack;

public class ImplementQueueUsingStack {
    private Stack<Integer> stack1;
    private Stack<Integer> stack2;
    public ImplementQueueUsingStack() {
        stack1 = new Stack<>();
        stack2 = new Stack<>();
    }

    public void push(int x) {
        this.stack1.push(x);
    }

    public int pop() {
        while (!stack1.isEmpty()) {
            stack2.push(stack1.pop());
        }
        int result = stack2.pop();
        while (!stack2.isEmpty()) {
            stack1.push(stack1.pop());
        }
        return result;
    }

    public int peek() {
        while (!stack1.isEmpty()) {
            stack2.push(stack1.pop());
        }
        int result = stack2.peek();
        while (!stack2.isEmpty()) {
            stack1.push(stack1.pop());
        }
        return result;
    }

    public boolean empty() {
        return this.stack1.isEmpty() & this.stack2.isEmpty();
    }
}
