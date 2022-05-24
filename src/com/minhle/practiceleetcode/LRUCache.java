package com.minhle.practiceleetcode;

import java.util.HashMap;
import java.util.Map;

public class LRUCache {

    static class DNode {
        int key;
        int value;
        DNode next;
        DNode prev;

        public DNode(int key, int value) {
            this.key = key;
            this.value = value;
        }
    }

    static class DLinkedList {
        int size;
        int currentSize;
        DNode head;
        DNode tail;

        public DLinkedList(int size) {
            this.size = size;
            this.currentSize = 0;
            head = new DNode(-1, -1);
            tail = new DNode(-1, -1);
            head.next = tail;
            tail.prev = head;
        }

        public void addToHead(DNode node) {
            DNode currNext = head.next;
            node.next = currNext;
            currNext.prev = node;
            head.next = node;
            node.prev = head;
            this.currentSize++;
        }

        public DNode removeTail() {
            DNode currTail = tail.prev;
            DNode newTail = currTail.prev;
            newTail.next = tail;
            tail.prev = newTail;
            this.currentSize--;
            return currTail;
        }

        public void moveToHead(DNode node) {
            node.prev.next = node.next;
            node.next.prev = node.prev;
            this.currentSize --;
            addToHead(node);
        }

        public boolean isFull() {
            return this.currentSize >= this.size;
        }
    }


    DLinkedList cached;
    Map<Integer, DNode> map;
    public LRUCache(int capacity) {
        this.cached = new DLinkedList(capacity);
        map = new HashMap<>();
    }

    public int get(int key) {
        int value = -1;
        if (map.containsKey(key)) {
            value = map.get(key).value;
            DNode curr = map.get(key);
            cached.moveToHead(curr);
        }
        return value;
    }

    public void put(int key, int value) {
        if (map.containsKey(key)) {
            DNode curr = map.get(key);
            curr.value = value;
            cached.moveToHead(curr);
        }
        else {
            if (cached.isFull()) {
                DNode tail = cached.removeTail();
                map.remove(tail.key);
            }
            DNode newNode = new DNode(key, value);
            cached.addToHead(newNode);
            map.put(key, newNode);
        }
    }
}