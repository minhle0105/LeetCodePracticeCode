package com.minhle.practiceleetcode;

public class FindWinnerInACircularGame {

    static class Player {
        int id;
        Player prev;
        Player next;

        public Player(int id) {
            this.id = id;
        }
        void setNext(Player next) {
            this.next = next;
        }
        void setPrev(Player prev) {
            this.prev = prev;
        }
    }

    public int findTheWinner(int n, int k) {
        Player p = new Player(-1);
        Player curr = p;
        for (int i = 1; i <= n; i++) {
            Player player = new Player(i);
            curr.next = player;
            player.prev = curr;
            curr = curr.next;
        }
        curr.next = p.next;
        p = p.next;
        p.prev = curr;
        Player lastPlayer = find(p, n, k);
        return lastPlayer.id;
    }

    private Player find(Player currentPlayer, int remaining, int k) {
        if (remaining == 1) {
            return currentPlayer;
        }
        else {
            int count = 1;
            Player removed = currentPlayer;
            while (count < k) {
                removed = removed.next;
                count++;
            }
            removed.prev.next = removed.next;
            removed.next.prev = removed.prev;
            currentPlayer = removed.next;
            remaining -= 1;
            return find(currentPlayer, remaining, k);

        }
    }
}
