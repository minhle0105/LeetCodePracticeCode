package com.minhle.practiceleetcode;

public class DesignCircularDequeue {
    static class Node {
        int value;
        Node next;
        Node prev;

        public Node() {
        }

        public Node(int value, Node next) {
            this.value = value;
            this.next = next;
        }

        public Node(int value) {
            this.value = value;
        }
    }

    static class MyCircularDeque {

        Node head;
        Node tail;
        int currentSize;
        int maxSize;

        public MyCircularDeque(int k) {
            this.currentSize = 0;
            this.maxSize = k;
            this.head = null;
            this.tail = null;
        }

        public boolean insertFront(int value) {
            if (this.isFull()) {
                return false;
            }
            Node newHead = new Node(value);
            if (this.head == null) {
                this.head = newHead;
                this.tail = newHead;
                this.tail.next = this.head;
                this.tail.prev = this.head;
                this.head.next = this.tail;
                this.head.prev = this.tail;
            }
            else {
                newHead.next = this.head;
                this.head.prev = newHead;
                this.head = newHead;
                this.tail.next = newHead;
                this.head.prev = this.tail;
            }
            this.currentSize++;
            return true;
        }

        public boolean insertLast(int value) {
            if (this.isFull()) {
                return false;
            }
            Node newTail = new Node(value);
            if (this.tail == null) {
                this.head = newTail;
                this.tail = newTail;
                this.head.next = this.tail;
                this.head.prev = this.tail;
                this.tail.next = this.head;
                this.tail.prev = this.head;

            }
            else {
                this.tail.next = newTail;
                newTail.prev = this.tail;
                this.tail = newTail;
                this.tail.next = this.head;
                this.head.prev = this.tail;
            }
            this.currentSize++;
            return true;
        }

        public boolean deleteFront() {
            if (this.isEmpty()) {
                return false;
            }
            if (this.currentSize == 1) {
                this.head = null;
                this.tail = null;
            }
            else {
                this.head = this.head.next;
                this.head.prev = this.tail;
                this.tail.next = this.head;

            }
            this.currentSize--;
            return true;
        }

        public boolean deleteLast() {
            if (this.isEmpty()) {
                return false;
            }
            if (this.currentSize == 1) {
                this.head = null;
                this.tail = null;
            }
            else {
                Node newTail = this.tail.prev;
                this.tail = newTail;
                this.tail.next = this.head;
                this.head.prev = newTail;
            }
            this.currentSize--;
            return true;
        }

        public int getFront() {
            if (this.isEmpty()) {
                return -1;
            }
            return this.head.value;
        }

        public int getRear() {
            if (this.isEmpty()) {
                return -1;
            }
            return this.tail.value;
        }

        public boolean isEmpty() {
            return this.currentSize == 0;
        }

        public boolean isFull() {
            return this.currentSize == this.maxSize;
        }
    }
}
