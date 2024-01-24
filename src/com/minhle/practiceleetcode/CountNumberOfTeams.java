package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class CountNumberOfTeams {
    public int numTeams(int[] rating) {
        int[][] lessGreater = new int[rating.length][2];//0 <- tuple stores left side less ,1 stores right side greater;
        for(int i=0; i < rating.length;i++){
            int left=0,leftTotal=0;
            while(left < i){
                if (rating[left] < rating[i])
                    leftTotal++;
                left++;
            }
            lessGreater[i][0] = leftTotal;
            int right = i+1, rightTotal = 0;
            while(right < rating.length){
                if(rating[right] > rating[i])
                    rightTotal++;
                right++;
            }
            lessGreater[i][1] = rightTotal;
        }

        int total =0;
        for (int i=0; i < rating.length; i++){
            int a = lessGreater[i][0];
            int b = lessGreater[i][1];
            int c = (i - lessGreater[i][0]);
            int d = (rating.length - 1 - i - lessGreater[i][1]);
            total += (a * b) + (c * d);
        }
        return total;
    }

    @Test
    void test1() {
        int[] rating = {2,5,3,4,1};
        Assertions.assertEquals(3, numTeams(rating));
    }
}
