package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;

class Airport implements Comparable<Airport> {
    int id;
    int cost;
    int distance;

    public Airport(int id, int cost, int distance) {
        this.id = id;
        this.cost = cost;
        this.distance = distance;
    }


    @Override
    public int compareTo(Airport o) {
        return Integer.compare(this.cost, o.cost);
    }
}

public class CheapestFlightWithinKStops {

    static List<List<Airport>> graph;
    static int[] distance;
    static int[] cost;

    private static void prepareData(int n, int[][] flights) {
        graph = new ArrayList<>();
        for (int i = 0; i <= n+1; i++) {
            graph.add(new ArrayList<>());
        }
        for (int[] flight : flights) {
            int from = flight[0];
            int to = flight[1];
            int cost = flight[2];
            graph.get(from).add(new Airport(to, cost, 0));
        }
        distance = new int[graph.size()];
        cost = new int[graph.size()];
        for (int i = 0; i < graph.size(); i++) {
            distance[i] = Integer.MAX_VALUE;
            cost[i] = Integer.MAX_VALUE;
        }
    }

    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        PriorityQueue<Airport> heap = new PriorityQueue<>();
        prepareData(n, flights);
        heap.add(new Airport(src, 0, 0));
        cost[src] = 0;
        distance[src] = -1;
        while (!heap.isEmpty()) {
            Airport thisAirport = heap.remove();
            int currentAirportId = thisAirport.id;
            int currentAirportCost = thisAirport.cost;
            if (thisAirport.id == dst) {
                return cost[thisAirport.id];
            }
            if (cost[currentAirportId] != currentAirportCost) {
                continue;
            }
            if (thisAirport.distance > k) {
                continue;
            }
            for (int i = 0; i < graph.get(currentAirportId).size(); i++) {
                Airport nextAirport = graph.get(currentAirportId).get(i);
                if (currentAirportCost + nextAirport.cost < cost[nextAirport.id]) {
                    cost[nextAirport.id] = currentAirportCost + nextAirport.cost;
                    distance[nextAirport.id] = distance[currentAirportId] + 1;
                    heap.add(new Airport(nextAirport.id, cost[nextAirport.id], distance[nextAirport.id]));
                }
                else if (nextAirport.distance < distance[nextAirport.id]) {
                    heap.add(new Airport(nextAirport.id, cost[nextAirport.id], nextAirport.distance));
                    distance[nextAirport.id] = nextAirport.distance;
                }
            }
        }
        return cost[dst] == Integer.MAX_VALUE ? -1 : cost[dst];
    }

    @Test
    void firstTest() {
        int n = 3;
        int[][] flights = {{0,1,100},{1,2,100},{0,2,500}};
        int src = 0;
        int dst = 2;
        int k = 1;
        int expected = 200;
        int actual = findCheapestPrice(n, flights, src, dst, k);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void secondTest() {
        int n = 3;
        int[][] flights = {{0,1,100},{1,2,100},{0,2,500}};
        int src = 0;
        int dst = 2;
        int k = 0;
        int expected = 500;
        int actual = findCheapestPrice(n, flights, src, dst, k);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void failedTest() {
        int n = 4;
        int[][] flights = {{0,1,1},{0,2,5},{1,2,1},{2,3,1}};
        int src = 0;
        int dst = 3;
        int k = 1;
        int expected = 6;
        int actual = findCheapestPrice(n, flights, src, dst, k);
        Assertions.assertEquals(expected, actual);
    }


}
