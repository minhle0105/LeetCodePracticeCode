package com.minhle.practiceleetcode;

public class DesignCircularQueue {

}

class CircularNode {
    int value;
    CircularNode nextNode;

    public CircularNode() {
    }

    public CircularNode(int value, CircularNode nextNode) {
        this.value = value;
        this.nextNode = nextNode;
    }

    public CircularNode(int value) {
        this.value = value;
    }

    void setNextNode(CircularNode nextNode) {
        this.nextNode = nextNode;
    }
}

class MyCircularQueue {

    CircularNode front;
    CircularNode back;
    int size;
    int currentSize;

    public MyCircularQueue(int k) {
        size = k;
        currentSize = 0;
        front = null;
        back = null;
    }

    public boolean enQueue(int value) {
        if (currentSize == size) {
            return false;
        }
        CircularNode newNode = new CircularNode(value);
        if (front == null) {
            front = newNode;
            back = newNode;
            front.setNextNode(back);
            back.setNextNode(front);
        }
        else {
            back.setNextNode(newNode);
            newNode.setNextNode(front);
            back = newNode;
        }
        currentSize++;
        return true;
    }

    public boolean deQueue() {
        if (isEmpty()) {
            return false;
        }
        if (currentSize == 1) {
            back = null;
            front = null;
        }
        else {
            front = front.nextNode;
        }
        currentSize--;
        return true;
    }

    public int Front() {
        return front != null ? front.value : -1;
    }

    public int Rear() {
        return back != null ? back.value : -1;
    }

    public boolean isEmpty() {
        return currentSize == 0;
    }

    public boolean isFull() {
        return currentSize == size;
    }
}
