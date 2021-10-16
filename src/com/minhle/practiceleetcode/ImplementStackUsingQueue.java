package com.minhle.practiceleetcode;

import java.util.LinkedList;
import java.util.Queue;

public class ImplementStackUsingQueue {

    private Queue<Integer> queue1;
    private Queue<Integer> queue2;

    public ImplementStackUsingQueue() {
        this.queue1 = new LinkedList<>();
        this.queue2 = new LinkedList<>();
    }

    public void push(int x) {
        this.queue1.add(x);
    }

    public int pop() {
        int queueSize = this.queue1.size();
        int count = 0;
        while (count < queueSize - 1) {
            this.queue2.add(this.queue1.remove());
            count++;
        }
        int popValue = this.queue1.remove();
        while (!this.queue2.isEmpty()) {
            this.queue1.add(this.queue2.remove());
        }
        return popValue;
    }

    public int top() {
        int queueSize = this.queue1.size();
        int count = 0;
        while (count < queueSize - 1) {
            this.queue2.add(this.queue1.remove());
            count++;
        }
        int topValue = this.queue1.peek();
        this.queue2.add(this.queue1.remove());
        while (!this.queue2.isEmpty()) {
            this.queue1.add(this.queue2.remove());
        }
        return topValue;
    }

    public boolean empty() {
        return this.queue1.isEmpty() && this.queue2.isEmpty();
    }

    public static void main(String[] args) {
        ImplementStackUsingQueue obj = new ImplementStackUsingQueue();
        obj.push(1);
        obj.push(2);
        int param_2 = obj.top();
        int param_3 = obj.pop();
        boolean param_4 = obj.empty();
    }
}
