package com.minhle.practiceleetcode;

public class Fibonacci {
      public static int solution(int n) {
            if (n == 0) {
                  return 0;
            }
            int[] fib = new int[n+1];
            fib[0] = 0;
            fib[1] = 1;
            for (int i = 2; i <= n; i ++) {
                  fib[i] = fib[i-2] + fib[i-1];
            }
            return fib[n];
      }
}
